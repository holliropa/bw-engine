#pragma once


namespace glfw {
    namespace enums {
        enum class ContextReleaseBehavior {
            Any   = GLFW_ANY_RELEASE_BEHAVIOR,
            Flush = GLFW_RELEASE_BEHAVIOR_FLUSH,
            None  = GLFW_RELEASE_BEHAVIOR_NONE
        };
    }

    using namespace enums;
}
