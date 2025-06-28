#pragma once

#include <iostream>
#include "bw/engine/gl.h"

namespace bw::engine {
    class FPSCounter {
    private:
        double lastUpdateTime_ = 0.0;
        unsigned frameCount_ = 0;

    public:
        void update() {
            frameCount_++;
            const auto currentTime = glfw::getTime();

            if (const auto timeSinceUpdate = currentTime - lastUpdateTime_; timeSinceUpdate > 1.0) {
                const auto fps = static_cast<double>(frameCount_) / timeSinceUpdate;
                std::cout << "FPS: " << fps << '\n';
                lastUpdateTime_ = currentTime;
                frameCount_ = 0;
            }
        }
    };
}
