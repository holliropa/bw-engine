#pragma once

namespace glad {
    namespace enums {
        enum class IndexType : GLenum {
            UnsignedByte  = GL_UNSIGNED_BYTE,
            UnsignedShort = GL_UNSIGNED_SHORT,
            UnsignedInt   = GL_UNSIGNED_INT,
        };
    }

    using namespace enums;
}
