#pragma once

#include "texture.h"
#include "../enums/pixel_data_internal_format.h"
#include "../enums/pixel_data_format.h"
#include "../enums/pixel_date_type.h"

namespace glad {
    class Texture2D : public Texture<TextureType::Texture2D> {
    public:
        void upload(const GLint level,
                    const PixelDataInternalFormat internalFormat,
                    const GLsizei width,
                    const GLsizei height,
                    const PixelDataFormat format,
                    const PixelDataType type,
                    const GLvoid* const data) {
            glTexImage2D(GL_TEXTURE_2D,
                         level,
                         static_cast<GLint>(internalFormat),
                         width,
                         height,
                         0,
                         static_cast<GLenum>(format),
                         static_cast<GLenum>(type),
                         data);
        }
    };
}
