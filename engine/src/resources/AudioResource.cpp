#include <resources/AudioResource.h>
#include <core/Logger.h>

namespace resources {
    bool AudioResource::load() {
        LOG_INFO("[AudioResource] Loading {}", m_path);

        m_audioData = nullptr;
        m_loaded = true;

        return true;
    }

    void AudioResource::unload() {
        m_audioData = nullptr;
        m_loaded = false;
    }
}