#include "SDL3/SDL_gamepad.h"
#include "SDL3/SDL_mouse.h"
#include <core/Game.h>
#include <iostream>

namespace core {
    void Game::onRender() { }
    void Game::onUpdate(double dt) {
        auto& input = getInput();

        if (input.isKeyPressed(SDL_SCANCODE_SPACE))
            std::cout << "[KEYBOARD] Space pressed\n";

        if (input.isKeyDown(SDL_SCANCODE_SPACE))
            std::cout << "[KEYBOARD] Holding SPACE\n";
 
        if (input.isKeyReleased(SDL_SCANCODE_SPACE))
            std::cout << "[KEYBOARD] Space released\n";

        if (input.isButtonPressed(SDL_GAMEPAD_BUTTON_SOUTH))
            std::cout << "[GAMEPAD] Button A pressed\n";

        if (input.isButtonDown(SDL_GAMEPAD_BUTTON_SOUTH))
            std::cout << "[GAMEPAD] Holding A\n";

        if (input.isButtonReleased(SDL_GAMEPAD_BUTTON_SOUTH))
            std::cout << "[GAMEPAD] Button A released\n";

        if (input.isMousePressed(SDL_BUTTON_MIDDLE))
            std::cout << "[MOUSE] Middle mouse button pressed\n";

        if (input.isMouseDown(SDL_BUTTON_MIDDLE))
            std::cout << "[MOUSE] Holding middle mouse button\n";

        if (input.isMouseReleased(SDL_BUTTON_MIDDLE))   
            std::cout << "[MOUSE] Middle mouse button released\n";
    }

    void Game::onHandleEvents(const SDL_Event& e) { }

    void Game::onQuit() { }
}