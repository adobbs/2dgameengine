#ifndef SCRIPTSYSTEM_H
#define SCRIPTSYSTEM_H

#include "../ECS/ECS.h"
#include "../Components/ScriptComponent.h"

class ScriptSystem: public System {
    public:
        ScriptSystem() {
            RequireComponent<ScriptComponent>();
        }

        void Update() {
            // Loop all entities that have a script component and invoke their Lua function
            for (auto entity: GetSystemEntities()) {
                const auto script = entity.GetComponent<ScriptComponent>();
                script.func(); // here is where we invoke a sol::function
            }
        }
};

#endif
