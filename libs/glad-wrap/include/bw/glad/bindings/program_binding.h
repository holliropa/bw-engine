#pragma once

#include "../program.h"

namespace glad {
    inline void Bind(const Program& program) {
        glUseProgram(static_cast<GLuint>(program.expose()));
    }

    inline void Unbind(const Program&) {
        glUseProgram(0);
    }

    inline bool IsBound(const Program& program) {
        GLint current_program;
        glGetIntegerv(GL_CURRENT_PROGRAM, &current_program);

        return static_cast<GLuint>(program.expose()) == static_cast<GLuint>(current_program);
    }

    inline void UnbindProgram() {
        glUseProgram(0);
    }
}
