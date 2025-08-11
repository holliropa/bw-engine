#pragma once

namespace glad {
    namespace enums {
        enum class WrapMode : GLenum {
            ClampToEdge       = GL_CLAMP_TO_EDGE,
            ClampToBorder     = GL_CLAMP_TO_BORDER,
            MirroredRepeat    = GL_MIRRORED_REPEAT,
            Repeat            = GL_REPEAT,
            MirrorClampToEdge = GL_MIRROR_CLAMP_TO_EDGE,
        };
    }

    using namespace enums;
}
