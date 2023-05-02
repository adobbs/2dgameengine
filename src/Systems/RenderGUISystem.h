#ifndef RENDERGUISYSTEM_H
#define RENDERGUISYSTEM_H

#include "../ECS/ECS.h"
#include <imgui/imgui.h>
#include <imgui/imgui_sdl.h>

class RenderGUISystem: public System {
    public:
        RenderGUISystem() = default;

        void Update() {
            ImGui::NewFrame();

            if (ImGui::Begin("Spawn enemies")) {
                ImGui::Text("TODO: Here is where we add GUI elements to our window...");
                // TODO:
            }
            ImGui::End();

            ImGui::Render();
            ImGuiSDL::Render(ImGui::GetDrawData());
        }
};

#endif
