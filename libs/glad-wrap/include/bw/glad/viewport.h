#pragma once


namespace glad {
    inline void Viewport(const GLint x,
                         const GLint y,
                         const GLsizei w,
                         const GLsizei h) {
        glViewport(x, y, w, h);
    }

    inline void Viewport(const GLsizei w,
                         const GLsizei h) {
        glViewport(0, 0, w, h);
    }
}
