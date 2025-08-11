#pragma once

#include "handle.h"

namespace glad {
    class VertexArrayHandle : public Handle {
    public:
        explicit VertexArrayHandle(const GLuint handle) {
            handle_ = handle;
            ownership_ = false;
        }

        VertexArrayHandle() {
            glGenVertexArrays(1, &handle_);
            ownership_ = true;
        }

        ~VertexArrayHandle() override {
            if (ownership_) {
                glDeleteVertexArrays(1, &handle_);
            }
        }

        VertexArrayHandle(VertexArrayHandle&&) noexcept = default;

        VertexArrayHandle& operator=(VertexArrayHandle&&) noexcept = default;
    };
}
