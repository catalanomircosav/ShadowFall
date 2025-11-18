#pragma once
#include <string>
#include <resources/types/ResourceType.h>

namespace resources {
    class Resource {
        public:
            Resource(std::string path) : m_path(std::move(path)) { }

            virtual ~Resource() = default;

            virtual bool load() = 0;
            virtual void unload() = 0;

            virtual ResourceType getType() const = 0;

            const std::string& getPath() const { return m_path; }

            bool isLoaded() const { return m_loaded; }

        protected:
            std::string m_path;
            bool m_loaded = false;
    };
}