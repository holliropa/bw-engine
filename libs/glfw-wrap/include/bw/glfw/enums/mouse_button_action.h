#pragma once


namespace glfw {
    namespace enums {
        enum class MouseButtonAction : int {
            Press   = GLFW_PRESS,
            Release = GLFW_RELEASE,
        };
    };

    using namespace enums;
}
