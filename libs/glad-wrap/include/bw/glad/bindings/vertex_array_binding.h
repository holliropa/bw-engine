#pragma once

#include "../vertex_array.h"

namespace glad {
    inline void Bind(const VertexArray& vertexArray) {
        glBindVertexArray(static_cast<GLuint>(vertexArray.expose()));
    }

    inline void Unbind(const VertexArray&) {
        glBindVertexArray(0);
    }

    inline bool IsBound(const VertexArray& vertexArray) {
        GLint vao;
        glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &vao);
        return static_cast<GLuint>(vertexArray.expose()) == static_cast<GLuint>(vao);
    }

    inline void UnbindVertexArray() {
        glBindVertexArray(0);
    }
}
