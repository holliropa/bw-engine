#pragma once

namespace glad {
    namespace enums {
        enum class DataType : GLenum {
            Byte          = GL_BYTE,
            Double        = GL_DOUBLE,
            Fixed         = GL_FIXED,
            Float         = GL_FLOAT,
            HalfFloat     = GL_HALF_FLOAT,
            Int           = GL_INT,
            Short         = GL_SHORT,
            UnsignedByte  = GL_UNSIGNED_BYTE,
            UnsignedInt   = GL_UNSIGNED_INT,
            UnsignedShort = GL_UNSIGNED_SHORT,
        };
    }

    using namespace enums;
}
