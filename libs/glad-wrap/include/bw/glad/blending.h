#pragma once

#include "enums/blend_function.h"

namespace glad {
    inline void BlendFunc(BlendFunction src, BlendFunction dst) {
        glBlendFunc(static_cast<GLenum>(src), static_cast<GLenum>(dst));
    }
}
