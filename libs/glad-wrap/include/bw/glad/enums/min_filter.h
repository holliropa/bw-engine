#pragma once

namespace glad {
    namespace enums {
        enum class MinFilter : GLenum {
            Nearest              = GL_NEAREST,
            Linear               = GL_LINEAR,
            NearestMipmapNearest = GL_NEAREST_MIPMAP_NEAREST,
            NearestMipmapLinear  = GL_NEAREST_MIPMAP_LINEAR,
            LinearMipmapNearest  = GL_LINEAR_MIPMAP_NEAREST,
            LinearMipmapLinear   = GL_LINEAR_MIPMAP_LINEAR,
        };
    }

    using namespace enums;
}
