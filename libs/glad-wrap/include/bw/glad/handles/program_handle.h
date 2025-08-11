#pragma once

#include "handle.h"

namespace glad {
    class ProgramHandle : public Handle {
    public:
        explicit ProgramHandle(const GLuint handle) {
            handle_ = handle;
            ownership_ = false;
        }

        ProgramHandle() {
            handle_ = glCreateProgram();
            ownership_ = true;
        }

        ~ProgramHandle() override {
            if (ownership_) {
                glDeleteProgram(handle_);
            }
        }

        ProgramHandle(ProgramHandle&&) noexcept = default;

        ProgramHandle& operator=(ProgramHandle&&) noexcept = default;
    };
}
