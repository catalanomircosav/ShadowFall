#include <resources/JSONResource.h>
#include <core/Logger.h>
#include <fstream>

namespace resources {

    bool JSONResource::load() {
        LOG_INFO("[JSONResource] Loading {}", m_path);

        std::ifstream file(m_path);
        if (!file.is_open()) {
            LOG_ERROR("[JSONResource] Failed to open file: {}", m_path);
            return false;
        }

        // TODO: load actual JSON's files
        m_loaded = true;
        return true;
    }

    void JSONResource::unload() {
        m_text.clear();
        m_loaded = false;
    }
}