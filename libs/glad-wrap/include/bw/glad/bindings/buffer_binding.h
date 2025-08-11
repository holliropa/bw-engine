#pragma once

#include "../buffer.h"
#include "../enums/buffer_type.h"
#include "../enums/buffer_binding.h"

namespace glad {
    template <BufferType BUFFER_TYPE>
    void Bind(const Buffer<BUFFER_TYPE>& buffer) {
        glBindBuffer(static_cast<GLenum>(BUFFER_TYPE), static_cast<GLuint>(buffer.expose()));
    }

    template <BufferType BUFFER_TYPE>
    void Unbind(const Buffer<BUFFER_TYPE>&) {
        glBindBuffer(static_cast<GLenum>(BUFFER_TYPE), 0);
    }

    constexpr BufferBinding GetBindingTarget(const BufferType bufferType) {
        switch (bufferType) {
        case BufferType::Array:
            return BufferBinding::Array;
        case BufferType::AtomicCounter:
            return BufferBinding::AtomicCounter;
        case BufferType::CopyRead:
            return BufferBinding::CopyRead;
        case BufferType::CopyWrite:
            return BufferBinding::CopyWrite;
        case BufferType::DispatchIndirect:
            return BufferBinding::DispatchIndirect;
        case BufferType::DrawIndirect:
            return BufferBinding::DrawIndirect;
        case BufferType::ElementArray:
            return BufferBinding::ElementArray;
        case BufferType::PixelPack:
            return BufferBinding::PixelPack;
        case BufferType::PixelUnpack:
            return BufferBinding::PixelUnpack;
        case BufferType::ShaderStorage:
            return BufferBinding::ShaderStorage;
        case BufferType::Texture:
            return BufferBinding::Texture;
        case BufferType::TransformFeedback:
            return BufferBinding::TransformFeedback;
        case BufferType::Uniform:
            return BufferBinding::Uniform;
        }
    }

    template <BufferType BUFFER_TYPE>
    bool IsBound(const Buffer<BUFFER_TYPE>& buffer) {
        GLint bound_buffer;
        glGetIntegerv(static_cast<GLenum>(GetBindingTarget(BUFFER_TYPE)), &bound_buffer);

        return static_cast<GLuint>(buffer.expose()) == static_cast<GLuint>(bound_buffer);
    }
}
