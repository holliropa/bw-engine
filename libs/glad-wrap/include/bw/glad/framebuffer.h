#pragma once

#include "renderbuffer.h"
#include "enums/framebuffer_target.h"
#include "enums/framebuffer_attachment.h"
#include "handles/framebuffer_handle.h"
#include "textures/texture.h"

namespace glad {
    class Framebuffer {
    public:
        Framebuffer() = default;

        Framebuffer(Framebuffer&&) noexcept = delete;

        Framebuffer& operator=(Framebuffer&&) noexcept = delete;

        explicit Framebuffer(const GLuint handle) : handle_{handle} {}

        void attach(FramebufferTarget target,
                    FramebufferAttachment attachment,
                    const TextureBase& texture,
                    const GLint level = 0) {
            glFramebufferTexture(static_cast<GLenum>(target),
                                 static_cast<GLenum>(attachment),
                                 static_cast<GLuint>(texture.expose()),
                                 level);
        }

        void attach(FramebufferTarget target,
                    FramebufferAttachment attachment,
                    const Renderbuffer& renderbuffer) {
            glFramebufferRenderbuffer(static_cast<GLenum>(target),
                                      static_cast<GLenum>(attachment),
                                      GL_RENDERBUFFER,
                                      static_cast<GLuint>(renderbuffer.expose()));
        }


        [[nodiscard]] const Handle& expose() const { return handle_; }

    private:
        FramebufferHandle handle_;
    };
}
