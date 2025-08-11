#pragma once

#include "../framebuffer.h"
#include "../enums/framebuffer_target.h"

namespace glad {
    inline void Bind(const Framebuffer& framebuffer, FramebufferTarget target = FramebufferTarget::Framebuffer) {
        glBindFramebuffer(static_cast<GLenum>(target), static_cast<GLuint>(framebuffer.expose()));
    }

    inline void Unbind(const Framebuffer&, FramebufferTarget target = FramebufferTarget::Framebuffer) {
        glBindFramebuffer(static_cast<GLenum>(target), 0);
    }
}
