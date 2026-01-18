#pragma once
#include "texture.h"

namespace glad {
    class Texture3D : public Texture<TextureType::Texture3D> {
    public:
        void upload(const GLint level,
                    const PixelDataInternalFormat internalFormat,
                    const GLsizei width,
                    const GLsizei height,
                    const GLsizei depth,
                    const PixelDataFormat format,
                    const PixelDataType type,
                    const GLvoid* const data) {
            glTexImage3D(GL_TEXTURE_3D,
                         level,
                         static_cast<GLint>(internalFormat),
                         width,
                         height,
                         depth,
                         0,
                         static_cast<GLenum>(format),
                         static_cast<GLenum>(type),
                         data
            );
        }

        void subImage(const GLint level,
                      const GLint xoffset,
                      const GLint yoffset,
                      const GLint zoffset,
                      const GLsizei width,
                      const GLsizei height,
                      const GLsizei depth,
                      const PixelDataFormat format,
                      const PixelDataType type,
                      const GLvoid* const data) {
            glTexSubImage3D(GL_TEXTURE_3D,
                            level,
                            xoffset,
                            yoffset,
                            zoffset,
                            width,
                            height,
                            depth,
                            static_cast<GLenum>(format),
                            static_cast<GLenum>(type),
                            data
            );
        }
    };
}
