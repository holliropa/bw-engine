#pragma once

namespace glad {
    inline void DepthMask(const bool mask) {
        glDepthMask(mask ? GL_TRUE : GL_FALSE);
    }

    inline bool DepthMask() {
        GLboolean value;
        glGetBooleanv(GL_DEPTH_WRITEMASK, &value);
        return value == GL_TRUE;
    }

    class TemporaryDepthMask {
        bool mask_;

    public:
        explicit TemporaryDepthMask(const bool mask) : mask_(DepthMask()) { DepthMask(mask); }

        ~TemporaryDepthMask() { DepthMask(mask_); }
    };
}
