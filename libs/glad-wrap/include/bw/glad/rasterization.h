#pragma once

#include "enums/poly_mode.h"

namespace glad {
    inline void LineWidth(const GLfloat width) {
        glLineWidth(width);
    }

    inline GLfloat LineWidth() {
        GLfloat value;
        glGetFloatv(GL_LINE_WIDTH, &value);
        return value;
    }

    class TemporaryLineWidth {
        GLfloat width_;

    public:
        explicit TemporaryLineWidth(const GLfloat width)
            : width_(LineWidth()) {
            LineWidth(width);
        }

        ~TemporaryLineWidth() {
            LineWidth(width_);
        }
    };

    inline void PolygonMode(PolyMode mode) {
        glPolygonMode(GL_FRONT_AND_BACK, static_cast<GLenum>(mode));
    }

    inline PolyMode PolygonMode() {
        GLint mode;
        glGetIntegerv(GL_POLYGON_MODE, &mode);
        return static_cast<PolyMode>(mode);
    }

    inline void PolygonOffset(const GLfloat factor = 0, const GLfloat units = 0) {
        glPolygonOffset(factor, units);
    }

    class TemporaryPolygonMode {
        PolyMode mode_;

    public:
        explicit TemporaryPolygonMode(const PolyMode mode)
            : mode_(PolygonMode()) {
            PolygonMode(mode);
        }

        ~TemporaryPolygonMode() {
            PolygonMode(mode_);
        }
    };
}
