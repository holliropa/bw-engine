#include "bw/engine/application.h"

namespace bw::engine {
    Application::Application(int width, int height, const char* title) {
        if (!glfw::init())
            throw std::runtime_error("Failed to initialize GLFW\n");

        glfw::ContextHints{
            .contextVersionMajor = 3,
            .contextVersionMinor = 3,
            .openglProfile = glfw::OpenGLProfile::Core,
        }.apply();

        pWindow_ = std::make_unique<glfw::Window>(width, height, title);

        makeContextCurrent(*pWindow_);
    }

    Application::~Application() {
        pWindow_.reset();

        glfw::terminate();
    }
}
