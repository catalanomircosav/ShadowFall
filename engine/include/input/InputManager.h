#pragma once
#include <SDL3/SDL.h>
#include <array>

namespace input {
    class InputManager {
        public:
            static constexpr int MAX_KEYS = SDL_SCANCODE_COUNT;
            static constexpr int MAX_BUTTONS = 16;
            static constexpr int MAX_MOUSE_BUTTON = 8;

            InputManager();

            void nextFrame();

            void handleEvent(const SDL_Event& e);

            // --- Keyboard ---
            bool inline isKeyDown(SDL_Scancode sc) const { return m_keys_down[sc]; }
            bool inline isKeyPressed(SDL_Scancode sc) const { return m_keys_pressed[sc]; }
            bool inline isKeyReleased(SDL_Scancode sc) const { return m_keys_released[sc]; }

            // --- Gamepad ---
            bool isButtonDown(int) const;
            bool isButtonPressed(int) const;
            bool isButtonReleased(int) const;

            float getAxis(int) const;

            // --- Mouse ---
            // position
            int inline getMouseX() const { return m_mouse_x; }
            int inline getMouseY() const { return m_mouse_y; }

            // movement
            int inline getMouseDeltaX() const { return m_mouse_dx; }
            int inline getMouseDeltaY() const { return m_mouse_dy; }

            // scroll
            int inline getScrollX() const { return m_scroll_x; }
            int inline getScrollY() const { return m_scroll_y; }

            bool inline isMouseDown(int b) const { return m_mouse_down[b]; }
            bool inline isMousePressed(int b) const { return m_mouse_pressed[b]; }
            bool inline isMouseReleased(int b) const { return m_mouse_released[b]; }
             
        private:
            // keyboard states
            std::array<bool, MAX_KEYS> m_keys_down{};
            std::array<bool, MAX_KEYS> m_keys_pressed{};
            std::array<bool, MAX_KEYS> m_keys_released{};

            // gamepad states
            std::array<bool, MAX_BUTTONS> m_buttons_down{};
            std::array<bool, MAX_BUTTONS> m_buttons_pressed{};
            std::array<bool, MAX_BUTTONS> m_buttons_released{};

            float m_left_x = 0.0f;
            float m_left_y = 0.0f;
            float m_right_x = 0.0f;
            float m_right_y = 0.0f;

            // mouse states
            std::array<bool, MAX_MOUSE_BUTTON> m_mouse_down{};
            std::array<bool, MAX_MOUSE_BUTTON> m_mouse_pressed{};
            std::array<bool, MAX_MOUSE_BUTTON> m_mouse_released{};

            int m_mouse_x = 0;
            int m_mouse_y = 0;

            int m_mouse_dx = 0;
            int m_mouse_dy = 0;

            int m_scroll_x = 0;
            int m_scroll_y = 0;
    };
}