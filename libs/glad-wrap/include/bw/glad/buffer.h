#pragma once

#include <vector>
#include "handles/buffer_handle.h"
#include "enums/buffer_type.h"
#include "enums/buffer_usage.h"

namespace glad {
    template <BufferType BUFFER_TYPE>
    class Buffer {
    public:
        [[nodiscard]] static constexpr BufferType type() { return BUFFER_TYPE; }

        Buffer() = default;

        Buffer(Buffer&&) noexcept = default;

        Buffer& operator=(Buffer&&) noexcept = default;

        explicit Buffer(const GLuint handle) : handle_{handle} {}

        void data(const GLsizei size,
                  const void* data,
                  BufferUsage usage = BufferUsage::StaticDraw) {
            Bind(*this);
            glBufferData(static_cast<GLenum>(BUFFER_TYPE), size, data, static_cast<GLenum>(usage));
        }

        template <typename GLtype>
        void data(const std::vector<GLtype>& data,
                  BufferUsage usage = BufferUsage::StaticDraw) {
            Bind(*this);
            glBufferData(static_cast<GLenum>(BUFFER_TYPE),
                         data.size() * sizeof(GLtype),
                         data.data(),
                         static_cast<GLenum>(usage));
        }

        [[nodiscard]] GLint size() const {
            Bind(*this);

            GLint size;
            glGetBufferParameteriv(static_cast<GLenum>(BUFFER_TYPE), GL_BUFFER_SIZE, &size);
            return size;
        }

        [[nodiscard]] const Handle& expose() const { return handle_; }

    private:
        BufferHandle handle_;
    };

    using ArrayBuffer = Buffer<BufferType::Array>;
    using AtomicCounterBuffer = Buffer<BufferType::AtomicCounter>;
    using CopyReadBuffer = Buffer<BufferType::CopyRead>;
    using CopyWriteBuffer = Buffer<BufferType::CopyWrite>;
    using DispatchIndirectBuffer = Buffer<BufferType::DispatchIndirect>;
    using DrawIndirectBuffer = Buffer<BufferType::DrawIndirect>;
    using ElementArrayBuffer = Buffer<BufferType::ElementArray>;
    using PixelPackBuffer = Buffer<BufferType::PixelPack>;
    using PixelUnpackBuffer = Buffer<BufferType::PixelUnpack>;
    using ShaderStorageBuffer = Buffer<BufferType::ShaderStorage>;
    using TextureBuffer = Buffer<BufferType::Texture>;
    using TransformFeedbackBuffer = Buffer<BufferType::TransformFeedback>;
    using UniformBuffer = Buffer<BufferType::Uniform>;
}
