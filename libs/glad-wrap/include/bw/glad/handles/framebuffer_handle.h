#pragma once

#include "handle.h"

namespace glad {
    class FramebufferHandle final : public Handle {
    public:
        explicit FramebufferHandle(const GLuint handle) {
            handle_ = handle;
            ownership_ = false;
        }

        FramebufferHandle() {
            glGenFramebuffers(1, &handle_);
            ownership_ = true;
        }

        ~FramebufferHandle() override {
            if (ownership_) {
                glDeleteFramebuffers(1, &handle_);
            }
        }

        FramebufferHandle(FramebufferHandle&&) noexcept = default;

        FramebufferHandle& operator=(FramebufferHandle&&) noexcept = default;
    };
}
