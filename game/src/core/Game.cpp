#include <core/Game.h>
#include <iostream>

namespace core {
    void Game::onRender() {

    }

    void Game::onUpdate(double dt) {
    }

    void Game::onHandleEvents(const SDL_Event& e) {
        switch(e.type) {
            case SDL_EVENT_KEY_DOWN:
                std::cout << "[GAME::INFO] Key pressed.\n";
            break;

            default:
                break;
        }
    }

    void Game::onQuit() {
        
    }
}