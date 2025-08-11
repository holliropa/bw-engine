#pragma once

#include "handles/vertex_array_handle.h"

namespace glad {
    class VertexArray {
    public:
        VertexArray() = default;

        VertexArray(VertexArray &&) noexcept = delete;

        VertexArray &operator=(VertexArray &&) noexcept = delete;

        explicit VertexArray(const GLuint handle) : handle_{handle} {}

        [[nodiscard]] const Handle &expose() const { return handle_; }

    private:
        VertexArrayHandle handle_;
    };
}