#pragma once

#include "window.h"
#include "context.h"
#include "hints.h"

namespace glfw {
    [[nodiscard]] inline bool init() {
        return glfwInit() == GLFW_TRUE;
    }

    inline void terminate() {
        glfwTerminate();
    }

    [[nodiscard]] inline double getTime() {
        return glfwGetTime();
    }
}
