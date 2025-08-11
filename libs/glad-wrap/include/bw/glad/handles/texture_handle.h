#pragma once

#include "handle.h"

namespace glad {
    class TextureHandle : public Handle {
    public:
        explicit TextureHandle(const GLuint handle) {
            handle_ = handle;
            ownership_ = false;
        }

        TextureHandle() {
            glGenTextures(1, &handle_);
            ownership_ = true;
        }

        ~TextureHandle() override {
            if (ownership_) {
                glDeleteTextures(1, &handle_);
            }
        }

        TextureHandle(TextureHandle&&) noexcept = default;

        TextureHandle& operator=(TextureHandle&&) noexcept = default;
    };
}
