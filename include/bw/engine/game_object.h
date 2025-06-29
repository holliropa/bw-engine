#pragma once

#include "camera.h"

namespace bw::engine {
    class GameObject {
    public:
        virtual ~GameObject() = default;

        virtual void init() {}

        virtual void update(float deltaTime) {}

        virtual void render(const Camera& camera) {}
    };
}
