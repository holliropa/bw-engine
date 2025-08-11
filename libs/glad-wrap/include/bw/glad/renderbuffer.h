#pragma once

#include "enums/pixel_data_internal_format.h"
#include "handles/renderbuffer_handle.h"

namespace glad {
    class Renderbuffer {
    public:
        Renderbuffer() = default;

        Renderbuffer(Renderbuffer&&) noexcept = delete;

        Renderbuffer& operator=(Renderbuffer&&) noexcept = delete;

        explicit Renderbuffer(const GLuint handle) : handle_{handle} {}

        void storage(PixelDataInternalFormat internalFormat,
                     const GLsizei width,
                     const GLsizei height,
                     const GLsizei samples = 0) {
            glRenderbufferStorageMultisample(GL_RENDERBUFFER,
                                             samples,
                                             static_cast<GLenum>(internalFormat),
                                             width,
                                             height);
        }

        [[nodiscard]] const Handle& expose() const { return handle_; }

    private:
        RenderbufferHandle handle_;
    };
}
