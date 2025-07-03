#pragma once

#include "camera.h"

namespace bw::engine {
    class BaseObject {
    public:
        virtual ~BaseObject() = default;

        virtual void init() {}

        virtual void update(float deltaTime) {}

        virtual void render(const Camera& camera) {}
    };
}
