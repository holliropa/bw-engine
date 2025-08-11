#pragma once


namespace glad {
    namespace enums {
        enum class PrimitiveType : GLenum {
            Points                 = GL_POINTS,
            Lines                  = GL_LINES,
            LineLoop               = GL_LINE_LOOP,
            LineStrip              = GL_LINE_STRIP,
            Triangles              = GL_TRIANGLES,
            TriangleStrip          = GL_TRIANGLE_STRIP,
            TriangleFan            = GL_TRIANGLE_FAN,
            LinesAdjacency         = GL_LINES_ADJACENCY,
            LineStripAdjacency     = GL_LINE_STRIP_ADJACENCY,
            TrianglesAdjacency     = GL_TRIANGLES_ADJACENCY,
            TriangleStripAdjacency = GL_TRIANGLE_STRIP_ADJACENCY,
        };
    }

    using namespace enums;
}
