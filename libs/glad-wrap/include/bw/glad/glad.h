#pragma once

#include "bindings.h"
#include "blending.h"
#include "buffer.h"
#include "capabilities.h"
#include "clearing.h"
#include "drawing.h"
#include "framebuffer.h"
#include "program.h"
#include "rasterization.h"
#include "renderbuffer.h"
#include "shader.h"
#include "texture.h"
#include "uniform.h"
#include "vertex_array.h"
#include "vertex_attribute.h"
#include "viewport.h"

namespace glad {
    [[nodiscard]] inline bool load() {
        return gladLoaderLoadGL();
    }

    inline void unload() {
        gladLoaderUnloadGL();
    }
}
