#pragma once
#include <resources/Resource.h>

namespace resources {

    class JSONResource : public Resource {
    public:
        JSONResource(const std::string& path)
            : Resource(path) {}

        bool load() override;
        void unload() override;

        ResourceType getType() const override { return ResourceType::JSON; }

        const std::string& getText() const { return m_text; }

    private:
        std::string m_text;
    };
}