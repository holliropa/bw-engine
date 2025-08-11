#pragma once

#include "../texture.h"
#include "../enums/texture_unit.h"

namespace glad {
    inline void ActiveTextureUnit(TextureUnit unit) {
        glActiveTexture(static_cast<GLenum>(unit));
    }

    template <TextureType TEXTURE_TYPE>
    void Bind(const Texture<TEXTURE_TYPE>& texture) {
        glBindTexture(static_cast<GLenum>(TEXTURE_TYPE), static_cast<GLuint>(texture.expose()));
    }
}
