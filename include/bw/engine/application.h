#pragma once

#include <memory>

#include "gl.h"

namespace bw::engine {
    class Application {
    private:
        std::unique_ptr<glfw::Window> pWindow_;

    public:
        Application(int width, int height, const char* title);
        ~Application();

        [[nodiscard]] glfw::Window& getWindow() const {
            return *pWindow_;
        }
    };
}
