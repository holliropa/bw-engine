#pragma once

#include "enums/data_type.h"

namespace glad {
    class VertexAttribute {
    public:
        explicit VertexAttribute(const GLuint location)
            : location_(location) {}

        VertexAttribute& pointer(const GLint values_per_vertex,
                                 DataType type,
                                 const bool normalized,
                                 const GLsizei stride,
                                 const void* offset_pointer = nullptr) {
            glVertexAttribPointer(location_,
                                  values_per_vertex,
                                  static_cast<GLenum>(type),
                                  normalized ? GL_TRUE : GL_FALSE,
                                  stride,
                                  offset_pointer);

            return *this;
        }

        VertexAttribute& divisor(const GLuint divisor) {
            glVertexAttribDivisor(location_, divisor);

            return *this;
        }

        VertexAttribute& enable() {
            glEnableVertexAttribArray(location_);

            return *this;
        }

        VertexAttribute& disable() {
            glDisableVertexAttribArray(location_);

            return *this;
        }

        [[nodiscard]] GLuint expose() const {
            return location_;
        }

    private:
        GLuint location_;
    };
}
