#pragma once

namespace glad {
    namespace enums {
        enum class Capability : GLenum {
            Blend                      = GL_BLEND,
            // ClipDistance               = GL_CLIP_DISTANCE,
            ColorLogicOp               = GL_COLOR_LOGIC_OP,
            CullFace                   = GL_CULL_FACE,
            DebugOutput                = GL_DEBUG_OUTPUT,
            DebugOutputSynchronous     = GL_DEBUG_OUTPUT_SYNCHRONOUS,
            DepthClamp                 = GL_DEPTH_CLAMP,
            DepthTest                  = GL_DEPTH_TEST,
            Dither                     = GL_DITHER,
            FramebufferSRGB            = GL_FRAMEBUFFER_SRGB,
            LineSmooth                 = GL_LINE_SMOOTH,
            Multisample                = GL_MULTISAMPLE,
            PolygonOffsetFill          = GL_POLYGON_OFFSET_FILL,
            PolygonOffsetLine          = GL_POLYGON_OFFSET_LINE,
            PolygonOffsetPoint         = GL_POLYGON_OFFSET_POINT,
            PolygonSmooth              = GL_POLYGON_SMOOTH,
            PrimitiveRestart           = GL_PRIMITIVE_RESTART,
            PrimitiveRestartFixedIndex = GL_PRIMITIVE_RESTART_FIXED_INDEX,
            RasterizedDiscard          = GL_RASTERIZER_DISCARD,
            SampleAlphaToCoverage      = GL_SAMPLE_ALPHA_TO_COVERAGE,
            SampleAlphaToOne           = GL_SAMPLE_ALPHA_TO_ONE,
            SampleCoverage             = GL_SAMPLE_COVERAGE,
            SampleShading              = GL_SAMPLE_SHADING,
            SampleMask                 = GL_SAMPLE_MASK,
            ScissorTest                = GL_SCISSOR_TEST,
            StencilTest                = GL_STENCIL_TEST,
            TextureCubeMapSeamless     = GL_TEXTURE_CUBE_MAP_SEAMLESS,
            ProgramPointSize           = GL_PROGRAM_POINT_SIZE,
        };
    }

    using namespace enums;
}
