#ifndef ECS_H
#define ECS_H

#include <bitset>
#include <vector>
#include <unordered_map>
#include <typeindex>
#include <set>

const unsigned int MAX_COMPONENTS = 32;

// === Signature === //
// Use a bitset to keep track of components in an entity.
// Also helps identify what entities a system uses.

typedef std::bitset<MAX_COMPONENTS> Signature;

struct IComponent {
    protected:
        static int nextId;
};

// === Component === //
// Assign a unique id to a component type

template <typename TComponent>
class Component: public IComponent {
    // Return unique id
    static int GetId() {
        static auto id = nextId++;
        return id;
    }
};

class Entity {
    private:
        int id;
    
    public:
        Entity(int id): id(id) {};
        Entity(const Entity& entity) = default;
        int GetId() const;

        Entity& operator =(const Entity& other) = default;
        bool operator ==(const Entity& other) const { return id == other.id; }
        bool operator !=(const Entity& other) const { return id != other.id; }
};

// === System === //
// The system processes entities with a specific signature

class System {
    private:
        Signature componentSignature;
        std::vector<Entity> entities;

    public:
        System() = default;
        ~System() = default;

        void AddEntityToSystem(Entity entity);
        void RemoveEntityFromSystem(Entity entity);
        std::vector<Entity> GetSystemEntities() const;
        const Signature& GetComponentSignature() const;

        // Define component types required by system
        template <typename T> void RequireComponent();
};

// === Pool === //
// A vector of objects of type T

class IPool {
    public:
        virtual ~IPool() {}
};

template <typename T>
class Pool: public IPool {
    private:
        std::vector<T> data;
    public:
        Pool(int size = 100) {
            data.resize(size);
        }
        virtual ~Pool() = default;

        bool isEmpty() const {
            return data.empty();
        }

        int GetSize() const {
            return data.size();
        }

        void Resize(int n) {
            data.resize(n);
        }

        void Clear() {
            data.clear();
        }

        void Add(T object) {
            data.push_back(object);
        }

        void Set(int index, T object) {
            data[index] = object;
        }

        T& Get(int index) { 
            return static_cast<T&>(data[index]);
        }

        T& operator[](unsigned int index) {
            return data[index];
        }
};

// === Registry === //
// The registry manages creation and destruction of entities, components, and systems

class Registry {
    private:
        int numEntities = 0;

        // Vector of component pools. Each pool contains all data for a certain component type.
        // Vector index = component type id
        // Pool index = entity id
        std::vector<IPool*> componentPools;

        // Vector of component signatures per entity. Stores which components are turned on for an entity.
        // Vector index = entity id
        std::vector<Signature> entityComponentSignatures;

        std::unordered_map<std::type_index, System*> systems;

        std::set<Entity> entitiesToBeAdded;
        std::set<Entity> entitiesToBeKilled;
    
    public:
        Registry() = default;

        void Update();

        Entity CreateEntity();
        void AddEntityToSystem(Entity entity);

        template <typename TComponent, typename ...TArgs> void AddComponent(Entity entity, TArgs&& ...args);
        template <typename TComponent> void RemoveComponent(Entity entity);
        template <typename TComponent> bool HasComponent(Entity entity) const;
        
        // TODO:
        // KillEntity()

        // AddComponent(Entity entity)
        // RemoveComponent(Entity entity)
        // HasComponent(Entity entity)
        // GetComponent(Entity entity)

        // AddSystem()
        // RemoveSystem()
        // HasSystem()
        // GetSystem()
};

template <typename TComponent>
void System::RequireComponent() {
    const auto componentId = Component<TComponent>::GetId();
    componentSignature.set(componentId);
}

template <typename TComponent, typename ...TArgs> 
void Registry::AddComponent(Entity entity, TArgs&& ...args) {
    const auto componentId = Component<TComponent>::GetId();
    const auto entityId = entity.GetId();

    if (componentId >= componentPools.size()) {
        componentPools.resize(componentId + 1, nullptr);
    }

    if (!componentPools[componentId]) {
        Pool<TComponent>* newComponentPool = new Pool<TComponent>();
        componentPools[componentId] = newComponentPool;
    }

    Pool<TComponent>* componentPool = componentPools[componentId];

    if (entityId >= componentPool->GetSize()) {
        componentPool->Resize(numEntities);
    }

    TComponent newComponent(std::forward<TArgs>(args...));

    componentPool->Set(entityId, newComponent);
    entityComponentSignatures[entityId].set(componentId);
}

template <typename TComponent>
void Registry::RemoveComponent(Entity entity) {
    const auto componentId = Component<TComponent>::GetId();
    const auto entityId = entity.GetId();
    entityComponentSignatures[entityId].set(componentId, false);
}

template <typename TComponent>
bool Registry::HasComponent(Entity entity) const {
    const auto componentId = Component<TComponent>::GetId();
    const auto entityId = entity.GetId();
    return entityComponentSignatures[entityId].test(componentId);
}

#endif
