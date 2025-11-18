#include <game/Game.h>
#include <core/Logger.h>

namespace game {

    void Game::onRender() { }

    void Game::onUpdate(double dt) {
        auto& input = getInput();

        if (input.isKeyPressed(SDL_SCANCODE_SPACE))
            LOG_TRACE("[KEYBOARD] Space pressed");

        if (input.isKeyDown(SDL_SCANCODE_SPACE))
            LOG_TRACE("[KEYBOARD] Holding SPACE");

        if (input.isKeyReleased(SDL_SCANCODE_SPACE))
            LOG_TRACE("[KEYBOARD] Space released");

        if (input.isButtonPressed(SDL_GAMEPAD_BUTTON_SOUTH))
            LOG_TRACE("[GAMEPAD] Button A pressed");

        if (input.isButtonDown(SDL_GAMEPAD_BUTTON_SOUTH))
            LOG_TRACE("[GAMEPAD] Holding A");

        if (input.isButtonReleased(SDL_GAMEPAD_BUTTON_SOUTH))
            LOG_TRACE("[GAMEPAD] Button A released");

        if (input.isMousePressed(SDL_BUTTON_MIDDLE))
            LOG_TRACE("[MOUSE] Middle mouse button pressed");

        if (input.isMouseDown(SDL_BUTTON_MIDDLE))
            LOG_TRACE("[MOUSE] Holding middle mouse button");

        if (input.isMouseReleased(SDL_BUTTON_MIDDLE))
            LOG_TRACE("[MOUSE] Middle mouse button released");
    }

    void Game::onHandleEvents(const SDL_Event& e) { }

    void Game::onQuit() { }
}
