#pragma once


namespace glfw {
    namespace enums {
        enum class ContextRobustness {
            NoRobustness        = GLFW_NO_ROBUSTNESS,
            NoResetNotification = GLFW_NO_RESET_NOTIFICATION,
            LoseContextOnReset  = GLFW_LOSE_CONTEXT_ON_RESET
        };
    }

    using namespace enums;
}
