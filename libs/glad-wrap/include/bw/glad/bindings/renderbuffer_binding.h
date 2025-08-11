#pragma once

#include "../renderbuffer.h"

namespace glad {
    inline void Bind(const Renderbuffer& renderbuffer) {
        glBindRenderbuffer(GL_RENDERBUFFER, static_cast<GLuint>(renderbuffer.expose()));
    }

    inline void Unbind(const Renderbuffer&) {
        glBindRenderbuffer(GL_RENDERBUFFER, 0);
    }
}
