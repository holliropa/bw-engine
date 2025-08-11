#pragma once

namespace glad {
    namespace enums {
        enum class MagFilter : GLenum {
            Nearest = GL_NEAREST,
            Linear  = GL_LINEAR,
        };
    }

    using namespace enums;
}
