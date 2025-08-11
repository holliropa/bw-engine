#pragma once

namespace glad {
    namespace enums {
        enum class PixelDataFormat : GLenum {
            Red              = GL_RED,
            RG               = GL_RG,
            RGB              = GL_RGB,
            BGR              = GL_BGR,
            RGBA             = GL_RGBA,
            BGRA             = GL_BGRA,
            Red_Integer      = GL_RED_INTEGER,
            RGB_Integer      = GL_RGB_INTEGER,
            BGR_Integer      = GL_BGR_INTEGER,
            RGBA_Integer     = GL_RGBA_INTEGER,
            BGRA_Integer     = GL_BGRA_INTEGER,
            Stencil_Index    = GL_STENCIL_INDEX,
            Depth_Components = GL_DEPTH_COMPONENT,
            Depth_Stencil    = GL_DEPTH_STENCIL,
        };
    }

    using namespace enums;
}
