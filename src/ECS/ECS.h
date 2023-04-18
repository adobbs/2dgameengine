#ifndef ECS_H
#define ECS_H

#include <bitset>
#include <vector>

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
        int GetId() const;
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

class Registry {
    // TODO
};

template <typename TComponent>
void System::RequireComponent() {
    const auto componentId = Component<TComponent>::GetId();
    componentSignature.set(componentId);
}

#endif
