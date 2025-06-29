#pragma once

#include "glm.h"

namespace bw::engine {
    class Camera {
    public:
        virtual ~Camera() = default;

        [[nodiscard]] virtual glm::mat4 get_view() const = 0;

        [[nodiscard]] virtual glm::mat4 get_projection() const = 0;
    };
}
