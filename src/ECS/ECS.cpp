#include "ECS.h"
#include "../Logger/Logger.h"

int Entity::GetId() const {
    return id;
}

void System::AddEntityToSystem(Entity entity) {
    entities.push_back(entity);
}

void System::RemoveEntityFromSystem(Entity entity) {
    entities.erase(std::remove_if(entities.begin(), entities.end(),[&entity](Entity other) {
        return entity.GetId() == other.GetId();
    }), entities.end());
}

std::vector<Entity> System::GetSystemEntities() const {
    return entities;
}

const Signature& System::GetComponentSignature() const {
    return componentSignature;
};

Entity Registry::CreateEntity() {
    int entityId;
    entityId = numEntities++;

    Entity entity(entityId);
    entitiesToBeAdded.insert(entity);

    Logger::Log("Entity created: " + std::to_string(entityId));

    return entity;
}

void Registry::Update() {
    // TODO:
    // Add entities
    // Remove entities
}
