#pragma once
#include <core/Application.h>

namespace core {
    class Game : public Application {
        public:
            void onRender() override;
            void onUpdate(double) override;
            void onHandleEvents(const SDL_Event&) override;
            void onQuit() override;
    };
}