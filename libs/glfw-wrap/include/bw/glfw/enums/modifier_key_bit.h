#pragma once


namespace glfw {
    namespace enums {
        enum class ModifierKeyBit : int {
            Shift    = GLFW_MOD_SHIFT,
            Control  = GLFW_MOD_CONTROL,
            Alt      = GLFW_MOD_ALT,
            Super    = GLFW_MOD_SUPER,
            CapsLock = GLFW_MOD_CAPS_LOCK,
            NumLock  = GLFW_MOD_NUM_LOCK,
        };
    }

    using namespace enums;
}
