#include <managers/ResourceManager.h>
#include <game/Game.h>
#include <memory>

namespace game {
    // global resource just for debugging
    std::shared_ptr<resources::Resource> player; 

    bool Game::onInit() {
        player = managers::ResourceManager::load(resources::ResourceType::Texture, "./assets/textures/player.png");    
    
        return true;
    }

    void Game::onRender() {
        static auto texResource = std::static_pointer_cast<resources::TextureResource>(player);
        SDL_Texture* tex = texResource->get();

        SDL_FRect srcRect = { 0, 0, 100, 100 };
        SDL_FRect destRect = { 200, 150, 200, 200 };

        SDL_RenderTexture(m_renderer, tex, &srcRect, &destRect);
    }

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
