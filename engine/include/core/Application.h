#pragma once
#include <SDL3/SDL.h>

namespace core {
    class Application {
        public:
            bool init(const char*, int, int);
            void run();

        protected:
            virtual void onRender() = 0;
            virtual void onUpdate(double) = 0;
            virtual void onHandleEvents(const SDL_Event&) = 0;
            virtual void onQuit() = 0;

        protected:
            SDL_Window* m_window;
            SDL_Renderer* m_renderer;

        private:
            void render();
            void update(double);
            void handleEvents();

            void quit();
        
        private:
            bool m_running;

    };
}