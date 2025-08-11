#pragma once

#include "enums/primitive_type.h"
#include "enums/index_type.h"

namespace glad {
    inline void DrawArrays(PrimitiveType type,
                           const GLint first,
                           const GLsizei count
    ) {
        glDrawArrays(static_cast<GLenum>(type), first, count);
    }

    inline void DrawArrays(PrimitiveType type,
                           const GLsizei count
    ) {
        glDrawArrays(static_cast<GLenum>(type), 0, count);
    }

    inline void DrawElements(PrimitiveType type,
                             const GLsizei count,
                             IndexType index_type
    ) {
        glDrawElements(static_cast<GLenum>(type), count, static_cast<GLenum>(index_type), nullptr);
    }

    inline void DrawElementsInstanced(PrimitiveType type,
                                      const GLsizei count,
                                      IndexType index_type,
                                      const GLsizei instance_count
    ) {
        glDrawElementsInstanced(static_cast<GLenum>(type),
                                count,
                                static_cast<GLenum>(index_type),
                                nullptr,
                                instance_count);
    }
}
