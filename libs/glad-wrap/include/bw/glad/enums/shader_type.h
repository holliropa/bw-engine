#pragma once


namespace glad {
    namespace enums {
        enum class ShaderType : GLenum {
            ComputeShader        = GL_COMPUTE_SHADER,
            VertexShader         = GL_VERTEX_SHADER,
            GeometryShader       = GL_GEOMETRY_SHADER,
            FragmentShader       = GL_FRAGMENT_SHADER,
            TessControlShader    = GL_TESS_CONTROL_SHADER,
            TessEvaluationShader = GL_TESS_EVALUATION_SHADER,
        };
    }

    using namespace enums;
}
