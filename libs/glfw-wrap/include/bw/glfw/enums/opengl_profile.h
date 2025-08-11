#pragma once


namespace glfw {
    namespace enums {
        enum class OpenGLProfile : int {
            Any    = GLFW_OPENGL_ANY_PROFILE,
            Compat = GLFW_OPENGL_COMPAT_PROFILE,
            Core   = GLFW_OPENGL_CORE_PROFILE,
        };
    }

    using namespace enums;
}
