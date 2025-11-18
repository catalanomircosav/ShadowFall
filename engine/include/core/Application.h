#pragma once
#include <SDL3/SDL.h>

#include <input/InputManager.h>


namespace core {
    class Application {
        public:
            bool init(const char*, int, int);
            void run();

        protected:
            virtual bool onInit() = 0;
            virtual void onRender() = 0;
            virtual void onUpdate(double) = 0;
            virtual void onHandleEvents(const SDL_Event&) = 0;
            virtual void onQuit() = 0;

            input::InputManager& getInput() { return m_input; }

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

            input::InputManager m_input;
            SDL_Gamepad* m_gamepad = nullptr;
    };
}