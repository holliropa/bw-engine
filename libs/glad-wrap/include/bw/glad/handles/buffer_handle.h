#pragma once

#include "handle.h"

namespace glad {
    class BufferHandle : public Handle {
    public:
        explicit BufferHandle(const GLuint handle) {
            handle_ = handle;
            ownership_ = false;
        }

        BufferHandle() {
            glGenBuffers(1, &handle_);
            ownership_ = true;
        }

        ~BufferHandle() override {
            if (ownership_) {
                glDeleteBuffers(1, &handle_);
            }
        }

        BufferHandle(BufferHandle&&) noexcept = default;

        BufferHandle& operator=(BufferHandle&&) noexcept = default;
    };
}
