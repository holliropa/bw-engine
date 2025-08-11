#pragma once

#include "handle.h"

namespace glad {
    class RenderbufferHandle final : public Handle {
    public:
        explicit RenderbufferHandle(const GLuint handle) {
            handle_ = handle;
            ownership_ = false;
        }

        RenderbufferHandle() {
            glGenRenderbuffers(1, &handle_);
            ownership_ = true;
        }

        ~RenderbufferHandle() override {
            if (ownership_) {
                glDeleteRenderbuffers(1, &handle_);
            }
        }

        RenderbufferHandle(RenderbufferHandle&&) noexcept = default;

        RenderbufferHandle& operator=(RenderbufferHandle&&) noexcept = default;
    };
}
