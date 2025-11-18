#include <core/Game.h>
#include <iostream>

namespace core {
    void Game::onRender() { }
    void Game::onUpdate(double dt) {
        auto& input = getInput();

        if (input.isKeyPressed(SDL_SCANCODE_SPACE))
            std::cout << "pressed\n";

        if (input.isKeyDown(SDL_SCANCODE_SPACE))
            std::cout << "down\n";

        if (input.isKeyReleased(SDL_SCANCODE_SPACE))
            std::cout << "released\n";

    }

    void Game::onHandleEvents(const SDL_Event& e) { }

    void Game::onQuit() { }
}