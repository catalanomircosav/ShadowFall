#include <input/InputManager.h>
#include <iostream>
namespace input {
    InputManager::InputManager() {
        m_keys_down.fill(false);
        m_keys_pressed.fill(false);
        m_keys_released.fill(false);

        m_buttons_down.fill(false);
        m_buttons_pressed.fill(false);
        m_buttons_released.fill(false);

        m_mouse_down.fill(false);
        m_mouse_pressed.fill(false);
        m_mouse_released.fill(false);

        m_mouse_x = m_mouse_y = 0;
        m_mouse_dx = m_mouse_dy = 0;
        m_scroll_x = m_scroll_y = 0;
        
        m_left_x = m_left_y = 0.0f;
        m_right_x = m_right_y = 0.0f;
    }

    void InputManager::nextFrame() {
        m_keys_pressed.fill(false);
        m_keys_released.fill(false);

        m_buttons_pressed.fill(false);
        m_buttons_released.fill(false);

        m_mouse_pressed.fill(false);
        m_mouse_released.fill(false);

        m_mouse_dx = m_mouse_dy = 0;
        m_scroll_x = m_scroll_y = 0;
    }

    void InputManager::handleEvent(const SDL_Event& e) {
        switch(e.type) {
            // --------------------
            // ----- KEYBOARD -----
            // --------------------
            case SDL_EVENT_KEY_DOWN: {
                SDL_Scancode sc = e.key.scancode;

                if(!m_keys_down[sc]) 
                    m_keys_pressed[sc] = true;

                m_keys_down[sc] = true;
                break;
            }

            case SDL_EVENT_KEY_UP: {
                SDL_Scancode sc = e.key.scancode;
                
                m_keys_down[sc] = false;
                m_keys_released[sc] = true;

                break;
            }

            // --------------------
            // ------- MOUSE ------
            // --------------------
            case SDL_EVENT_MOUSE_BUTTON_DOWN: {
                int b = e.button.button;
                if(b < MAX_MOUSE_BUTTON) {
                    if(!m_mouse_down[b]) m_mouse_pressed[b] = true;

                    m_mouse_down[b] = true;
                }

                break;
            }

            case SDL_EVENT_MOUSE_BUTTON_UP: {
                int b = e.button.button;
                if(b < MAX_MOUSE_BUTTON) {
                    m_mouse_down[b] = false;
                    m_mouse_released[b] = true;
                }

                break;
            }

            case SDL_EVENT_MOUSE_MOTION: {
                m_mouse_dx += e.motion.xrel;
                m_mouse_dy += e.motion.yrel;

                m_mouse_x = e.motion.x;
                m_mouse_y = e.motion.y;

                break;
            }

            case SDL_EVENT_MOUSE_WHEEL: {
                m_scroll_x += e.wheel.x;
                m_scroll_y += e.wheel.y;

                break;
            }

            // --------------------
            // ------ GAMEPAD -----
            // --------------------
            case SDL_EVENT_GAMEPAD_BUTTON_DOWN: {
                int b = e.gbutton.button;
                if(b < MAX_BUTTONS) {
                    if(!m_buttons_down[b]) m_buttons_pressed[b] = true;
                
                    m_buttons_down[b] = true;
                }

                break;
            }

            case SDL_EVENT_GAMEPAD_BUTTON_UP: {
                int b = e.gbutton.button;

                if(b < MAX_BUTTONS) {
                    m_buttons_down[b] = false;
                    m_buttons_released[b] = true;
                }

                break;
            }

            case SDL_EVENT_GAMEPAD_AXIS_MOTION: {
                switch(e.gaxis.axis) {
                    case SDL_GAMEPAD_AXIS_LEFTX:
                        m_left_x = e.gaxis.value;
                    break;

                    case SDL_GAMEPAD_AXIS_LEFTY:
                        m_left_y = e.gaxis.value;
                    break;

                    case SDL_GAMEPAD_AXIS_RIGHTX:
                        m_right_x = e.gaxis.value;
                    break;

                    case SDL_GAMEPAD_AXIS_RIGHTY:
                        m_right_y = e.gaxis.value;
                    break;
                }
                
                break;
            }
        }
    }

    bool InputManager::isButtonDown(int button) const {
        return (button < MAX_BUTTONS) && m_buttons_down[button];
    }


    bool InputManager::isButtonPressed(int button) const {
        return (button < MAX_BUTTONS) && m_buttons_pressed[button];
    }

    bool InputManager::isButtonReleased(int button) const {
        return (button < MAX_BUTTONS) && m_buttons_released[button];
    }

    float InputManager::getAxis(int axis) const {
        switch(axis) {
            case SDL_GAMEPAD_AXIS_LEFTX: return m_left_x; break;
            case SDL_GAMEPAD_AXIS_LEFTY: return m_left_y; break;
            case SDL_GAMEPAD_AXIS_RIGHTX: return m_right_x; break;
            case SDL_GAMEPAD_AXIS_RIGHTY: return m_right_y; break;
        }

        return 0.0f;
    }
}