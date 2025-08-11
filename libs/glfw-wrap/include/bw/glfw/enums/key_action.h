#pragma once


namespace glfw {
    namespace enums {
        enum class KeyAction : int {
            Press   = GLFW_PRESS,
            Release = GLFW_RELEASE,
            Repeat  = GLFW_REPEAT,
        };
    };

    using namespace enums;
}
