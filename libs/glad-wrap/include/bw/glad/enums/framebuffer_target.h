#pragma once

namespace glad {
    namespace enums {
        enum class FramebufferTarget: GLenum {
            Framebuffer     = GL_FRAMEBUFFER,
            DrawFramebuffer = GL_DRAW_FRAMEBUFFER,
            ReadFramebuffer = GL_READ_FRAMEBUFFER,
        };
    }

    using namespace enums;
}
