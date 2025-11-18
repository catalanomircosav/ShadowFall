#pragma once
#include <core/Application.h>

namespace game {
    class Game : public core::Application {
        public:
            void onRender() override;
            void onUpdate(double) override;
            void onHandleEvents(const SDL_Event&) override;
            void onQuit() override;
    };
}