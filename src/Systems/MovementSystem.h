#ifndef MOVEMENTSYSTEM_H
#define MOVEMENTSYSTEM_H

class MovementSystem: public System {
    public:
        MovementSystem();
        // TODO:
        // RequireComponent<TransformComponent>();
        // RequireComponent<...>);

        ~MovementSystem();

        void Update();
        // TODO:
        // Loop through all system entities
        // for (auto entity: GetEntities()) {
            // Update entity position based on velocity
        // }
};

MovementSystem::MovementSystem()
{
}

MovementSystem::~MovementSystem()
{
}


#endif
