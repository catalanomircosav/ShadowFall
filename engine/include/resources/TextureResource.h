#pragma once

#include "ResourceType.h"
#include "SDL3/SDL_render.h"
#include <resources/Resource.h>
#include <SDL3/SDL.h>

namespace resources {
    class TextureResource : public Resource {
        public:
            TextureResource(const std::string& path) : Resource(path) { }

            bool load() override;
            void unload() override;

            ResourceType getType() const override { return ResourceType::Texture; }

            SDL_Texture* get() const { return m_texture; }

        private:
            SDL_Texture* m_texture = nullptr;
    };
}