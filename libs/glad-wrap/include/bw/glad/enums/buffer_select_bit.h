#pragma once


namespace glad {
    namespace enums {
        enum class BufferSelectBit : GLenum {
            ColorBufferBit   = GL_COLOR_BUFFER_BIT,
            DepthBufferBit   = GL_DEPTH_BUFFER_BIT,
            StencilBufferBit = GL_STENCIL_BUFFER_BIT,
        };
    }

    using namespace enums;
}
