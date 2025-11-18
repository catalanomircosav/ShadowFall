#include <resources/TextureResource.h>
#include <core/Logger.h>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include <managers/ResourceManager.h>

namespace resources {

    bool TextureResource::load() {
        
        SDL_Surface* surface  = IMG_Load(m_path.c_str());
        if(!surface) return false;

        m_texture = SDL_CreateTextureFromSurface(managers::ResourceManager::getRenderer(), surface);
        if(!m_texture) return false;

        m_loaded = true;
        return m_loaded;
    }

    void TextureResource::unload() {
        if (m_texture) {
            SDL_DestroyTexture(m_texture);
            m_texture = nullptr;
        }
        m_loaded = false;
    }
}