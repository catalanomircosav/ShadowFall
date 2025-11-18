#pragma once
#include <core/Logger.h>
#include <resources/types/Resource.h>
#include <resources/JSONResource.h>
#include <resources/TextureResource.h>

namespace managers {
    class ResourceManager { 
        public:
            static std::shared_ptr<resources::Resource> load(resources::ResourceType type, const std::string& path) {
                if(m_cache.contains(path)) return m_cache[path];

                std::shared_ptr<resources::Resource> res = nullptr;

                switch(type) {
                    case resources::ResourceType::Texture:
                        res = std::make_shared<resources::TextureResource>(path);
                    break;
                    
                    case resources::ResourceType::JSON:
                        res = std::make_shared<resources::JSONResource>(path);
                    break;
                    
                    default:
                        LOG_ERROR("[ResourceManager] Unsupported resource type for {}", path);
                    break;
                }

                if(!res->load()) {
                    LOG_ERROR("[ResourceManager] Failed to load {}", path);
                    return nullptr;
                }
                
                m_cache[path] = res;
                return res;
            }

            static void clear() {
                for(auto& [path, resource] : m_cache) resource->unload();

                m_cache.clear();
            }
            
            static void setRenderer(SDL_Renderer* renderer) {
                s_renderer = renderer;
            }

            static SDL_Renderer* getRenderer() { return s_renderer; }
        
        private:
            static inline std::unordered_map<std::string, std::shared_ptr<resources::Resource>> m_cache;
            
            static inline SDL_Renderer* s_renderer;
    };
}