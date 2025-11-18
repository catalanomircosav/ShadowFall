#pragma once
#include <resources/Resource.h>

namespace resources {

    class AudioResource : public Resource {
    public:
        AudioResource(const std::string& path)
            : Resource(path) {}

        bool load() override;
        void unload() override;

        ResourceType getType() const override { return ResourceType::Audio; }

    private:
        // Placeholder for future audio buffer
        void* m_audioData = nullptr;
    };
}