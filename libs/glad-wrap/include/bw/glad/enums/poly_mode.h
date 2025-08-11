#pragma once


namespace glad {
    namespace enums {
        enum class PolyMode : GLenum {
            Point = GL_POINT,
            Line  = GL_LINE,
            Fill  = GL_FILL,
        };
    }

    using namespace enums;
}
