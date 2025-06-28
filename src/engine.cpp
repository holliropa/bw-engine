#include "bw/engine/engine.h"

#include <stdexcept>

namespace bw::engine {
    Engine::Engine() {
        if (!glad::load()) {
            throw std::runtime_error("GLAD Load Failed");
        }
    }

    Engine::~Engine() {
        glad::unload();
    }
}
