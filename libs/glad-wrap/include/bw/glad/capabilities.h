/*  TODO Capabilities require refactoring.
 *  There are differences between indexed capabilities.
 *  F.x. there is not GL_CLIP_DISTANCE (at least in current version of
 *  GLAD used), instead there are GL_CLIP_DISTANCEi (where i is an index),
 *  in addition each of indexed distances can be set to different stuff
 *
 *  Require more research.
 */

#pragma once

#include "enums/capability.h"

namespace glad {
    inline void Enable(Capability capability) {
        glEnable(static_cast<GLenum>(capability));
    }

    inline void Disable(Capability capability) {
        glDisable(static_cast<GLenum>(capability));
    }

    inline void SetCapability(Capability capability, const bool value) {
        if (value)
            glEnable(static_cast<GLenum>(capability));
        else
            glDisable(static_cast<GLenum>(capability));
    }

    inline bool IsEnabled(Capability capability) {
        return glIsEnabled(static_cast<GLenum>(capability));
    }

    class TemporaryCapability {
        Capability capability_;
        bool value_;

    public:
        explicit TemporaryCapability(const Capability capability, const bool value)
            : capability_(capability), value_(IsEnabled(capability)) {
            SetCapability(capability, value);
        }

        ~TemporaryCapability() { SetCapability(capability_, value_); }
    };
}
