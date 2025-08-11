#pragma once

#include "handle.h"
#include "../enums/shader_type.h"

namespace glad {
    class ShaderHandle : public Handle {
    public:
        explicit ShaderHandle(const GLuint handle) {
            handle_ = handle;
            ownership_ = false;
        }

        explicit ShaderHandle(ShaderType shader_t) {
            handle_ = glCreateShader(static_cast<GLenum>(shader_t));
            ownership_ = true;
        }

        ~ShaderHandle() override {
            if (ownership_) {
                glDeleteShader(handle_);
            }
        }

        ShaderHandle(ShaderHandle &&) noexcept = default;

        ShaderHandle &operator=(ShaderHandle &&) noexcept = default;
    };
}