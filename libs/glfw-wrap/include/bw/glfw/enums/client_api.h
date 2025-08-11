#pragma once


namespace glfw {
    namespace enums {
        enum class ClientApi {
            OpenGL    = GLFW_OPENGL_API,
            OpenGL_ES = GLFW_OPENGL_ES_API,
            NoApi     = GLFW_NO_API
        };
    }

    using namespace enums;
}
