#pragma once

#include "bitfield.h"
#include "enums/buffer_select_bit.h"

namespace glad {
    inline void ClearColor(const GLfloat r,
                           const GLfloat g,
                           const GLfloat b,
                           const GLfloat a = 1.0f) {
        glClearColor(r, g, b, a);
    }

    class ClearBuffers {
        Bitfield<BufferSelectBit> buffers_;

    public:
        ClearBuffers& Color() {
            buffers_ |= BufferSelectBit::ColorBufferBit;
            return *this;
        }

        ClearBuffers& Depth() {
            buffers_ |= BufferSelectBit::DepthBufferBit;
            return *this;
        }

        ClearBuffers& Stencil() {
            buffers_ |= BufferSelectBit::StencilBufferBit;
            return *this;
        }

        ~ClearBuffers() {
            if (static_cast<GLbitfield>(buffers_) != 0) {
                glClear(static_cast<GLbitfield>(buffers_));
            }
        }
    };

    inline ClearBuffers Clear() {
        return {};
    }
}
