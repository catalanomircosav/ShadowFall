#include <resources/TextureResource.h>
#include <core/Logger.h>
#include <SDL3/SDL.h>

namespace resources {

    bool TextureResource::load() {
        LOG_INFO("[TextureResource] Loading {}", m_path);

        // TODO: Load PNG with SDL_image later
        m_texture = nullptr;
        m_loaded = true;
        return true;
    }

    void TextureResource::unload() {
        if (m_texture) {
            SDL_DestroyTexture(m_texture);
            m_texture = nullptr;
        }
        m_loaded = false;
    }
}