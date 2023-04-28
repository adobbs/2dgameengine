#ifndef KEYBOARDCONTROLSYSTEM_H
#define KEYBOARDCONTROLSYSTEM_H

#include "../ECS/ECS.h"
#include "../EventBus/EventBus.h"
#include "../Events/KeyPressedEvent.h"
#include "../Logger/Logger.h"
#include "../Components/KeyboardControlledComponent.h"
#include "../Components/SpriteComponent.h"
#include "../Components/RigidBodyComponent.h"
#include <SDL2/SDL.h>

class KeyboardControlSystem: public System {
    public:
        KeyboardControlSystem() {
            RequireComponent<KeyboardControlledComponent>();
            RequireComponent<SpriteComponent>();
            RequireComponent<RigidBodyComponent>();
        }

        void SubscribeToEvents(std::unique_ptr<EventBus>& eventBus) {
            eventBus->SubscribeToEvent<KeyPressedEvent>(this, &KeyboardControlSystem::OnKeyPressed);
        }

        void OnKeyPressed(KeyPressedEvent& event) {
            for (auto entity: GetSystemEntities()) {
                const auto keyboardcontrol = entity.GetComponent<KeyboardControlledComponent>();
                auto& sprite = entity.GetComponent<SpriteComponent>();
                auto& rigidbody = entity.GetComponent<RigidBodyComponent>();

                switch (event.symbol) {
                    case SDLK_UP:
                        rigidbody.velocity = keyboardcontrol.upVelocity;
                        sprite.srcRect.y = 0;
                        break;
                    case SDLK_RIGHT:
                        rigidbody.velocity = keyboardcontrol.rightVelocity;
                        sprite.srcRect.y = 32;
                        break;
                    case SDLK_DOWN:
                        rigidbody.velocity = keyboardcontrol.downVelocity;
                        sprite.srcRect.y = 64;
                        break;
                    case SDLK_LEFT:
                        rigidbody.velocity = keyboardcontrol.leftVelocity;
                        sprite.srcRect.y = 96;
                        break;
                }
            }
        }
};

#endif
