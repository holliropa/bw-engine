#pragma once


namespace glad {
    namespace enums {
        enum class BufferBinding : GLenum {
            Array             = GL_ARRAY_BUFFER_BINDING,
            AtomicCounter     = GL_ATOMIC_COUNTER_BUFFER_BINDING,
            CopyRead          = GL_COPY_READ_BUFFER_BINDING,
            CopyWrite         = GL_COPY_WRITE_BUFFER_BINDING,
            DispatchIndirect  = GL_DISPATCH_INDIRECT_BUFFER_BINDING,
            DrawIndirect      = GL_DRAW_INDIRECT_BUFFER_BINDING,
            ElementArray      = GL_ELEMENT_ARRAY_BUFFER_BINDING,
            PixelPack         = GL_PIXEL_PACK_BUFFER_BINDING,
            PixelUnpack       = GL_PIXEL_UNPACK_BUFFER_BINDING,
            ShaderStorage     = GL_SHADER_STORAGE_BUFFER_BINDING,
            Texture           = GL_TEXTURE_BUFFER_BINDING,
            TransformFeedback = GL_TRANSFORM_FEEDBACK_BUFFER_BINDING,
            Uniform           = GL_UNIFORM_BUFFER_BINDING,
        };
    }

    using namespace enums;
}
