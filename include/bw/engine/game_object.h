#pragma once
#include <memory>

#include "camera.h"

namespace bw::engine {
    class GameObject {
    public:
        virtual ~GameObject() = default;

        virtual void init() {}

        virtual void update(float deltaTime) {}

        virtual void render(const std::shared_ptr<Camera>& camera) {}
    };
}
