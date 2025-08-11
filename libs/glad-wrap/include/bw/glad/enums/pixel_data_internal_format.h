/* TODO Add/refactor internal pixel data formats.
 *
 * For now available are only base formats.
 * There are base, sized and compressed formats. But not all values are
 * specified in khronos registry. But khronos wiki has much more detailed
 * explanation.
 *
 * Also found that in glTexImage2D the internalFormat is GLint rather
 * than GLenum.
 */

#pragma once

namespace glad {
    namespace enums {
        enum class PixelDataInternalFormat : GLenum {
            // Base Internal Format
            DepthComponent = GL_DEPTH_COMPONENT,
            DepthStencil   = GL_DEPTH_STENCIL,
            Red            = GL_RED,
            RG             = GL_RG,
            RGB            = GL_RGB,
            RGBA           = GL_RGBA,

            // TODO Refer to above explanation. Done for renderbuffer only
            Depth24Stencil8 = GL_DEPTH24_STENCIL8,

            // Sized Internal Format
            // R8       = GL_R8,
            // R8_SNORM = GL_R8_SNORM,
            // R16       = GL_R16,
            // R16_SNORM = GL_R16_SNORM,
            // RG8       = GL_RG8,
            // RG8_SNORM = GL_RG8_SNORM,
            // RG16      = GL_RG16,
            // RG16_SNORM = GL_RG16_SNORM,
            // R3G3B2    = GL_R3_G3_B2,
            // RGB4       = GL_RGB4,
            // RGB5     = GL_RGB5,
            // RGB8 = GL_RGB8,
            // RGB8_SNORM = GL_RGB8_SNORM,
            // RGB10 = GL_RGB10,
            // RGB12 = GL_RGB12,
            // RGB16 = GL_RGB16,
        };
    }

    using namespace enums;
}
