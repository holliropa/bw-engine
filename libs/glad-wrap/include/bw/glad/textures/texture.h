#pragma once

#include "../handles/texture_handle.h"
#include "../enums/texture_type.h"
#include "../enums/wrap_mode.h"
#include "../enums/min_filter.h"
#include "../enums/mag_filter.h"

namespace glad {
    class TextureBase {
    public:
        TextureBase() = default;

        TextureBase(TextureBase&&) noexcept = default;

        TextureBase& operator=(TextureBase&&) noexcept = default;

        explicit TextureBase(const GLuint handle) : handle_{handle} {}


        [[nodiscard]] const Handle& expose() const { return handle_; }

    protected:
        TextureHandle handle_;
    };

    template <TextureType TEXTURE_TYPE>
    class Texture : public TextureBase {
    public:
        void generateMipmap() {
            glGenerateMipmap(static_cast<GLenum>(TEXTURE_TYPE));
        }

        void wrapS(WrapMode wrap_mode) {
            glTexParameteri(static_cast<GLenum>(TEXTURE_TYPE),
                            GL_TEXTURE_WRAP_S,
                            static_cast<GLenum>(wrap_mode));
        }

        void wrapT(WrapMode wrap_mode) {
            glTexParameteri(static_cast<GLenum>(TEXTURE_TYPE),
                            GL_TEXTURE_WRAP_T,
                            static_cast<GLenum>(wrap_mode));
        }

        void wrapR(WrapMode wrap_mode) {
            glTexParameteri(static_cast<GLenum>(TEXTURE_TYPE),
                            GL_TEXTURE_WRAP_R,
                            static_cast<GLenum>(wrap_mode));
        }

        void minFilter(MinFilter min_filter) {
            glTexParameteri(static_cast<GLenum>(TEXTURE_TYPE),
                            GL_TEXTURE_MIN_FILTER,
                            static_cast<GLenum>(min_filter));
        }

        void magFilter(MagFilter mag_filter) {
            glTexParameteri(static_cast<GLenum>(TEXTURE_TYPE),
                            GL_TEXTURE_MAG_FILTER,
                            static_cast<GLenum>(mag_filter));
        }
    };
}
