#pragma once

#include "window.h"

namespace glfw {
    inline void makeContextCurrent(const Window& window) {
        glfwMakeContextCurrent(static_cast<GLFWwindow*>(window));
    }
}
