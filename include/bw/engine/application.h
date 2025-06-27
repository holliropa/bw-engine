#pragma once

#include <memory>

#include "gl_common.h"

namespace bw::engine {
    class Application {
    private:
        std::unique_ptr<glfw::Window> pWindow_;

    public:
        Application(int width, int height, const char* title);
        ~Application();

        glfw::Window& getWindow() const {
            return *pWindow_;
        }
    };
}
