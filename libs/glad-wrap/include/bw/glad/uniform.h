#pragma once

#include "enums/boolean.h"

namespace glad {
    class UniformObject {
    protected:
        GLint location_;

    public:
        static constexpr GLint kInvalidLocation = -1;

        explicit UniformObject(const GLint location = kInvalidLocation)
            : location_(location) {}

        UniformObject(const Program& program, const char* qualifier) {
            location_ = glGetUniformLocation(static_cast<GLuint>(program.expose()), qualifier);
        }

        [[nodiscard]] bool isValid() const { return location_ != kInvalidLocation; }

        [[nodiscard]] GLint expose() const { return location_; };

        explicit operator GLint() const { return location_; }
    };


#define DEFINE_UNIFORM(TYPE_ENUM, TYPE_GL, GL_FUNC)                     \
    template <GLsizei SIZE = 1>                                         \
    class Uniform##TYPE_ENUM : public UniformObject {                   \
    public:                                                             \
        explicit Uniform##TYPE_ENUM(GLint location = kInvalidLocation)  \
            : UniformObject(location) {}                                \
        Uniform##TYPE_ENUM(const Program& program,                      \
                           const char* qualifier)                       \
            : UniformObject(program, qualifier) {}                      \
        void set(const TYPE_GL* value) {                                \
            if (this->isValid()) {                                      \
                GL_FUNC(location_, SIZE, value);                   \
            }                                                           \
        }                                                               \
    };

#define DEFINE_MATRIX_UNIFORM(TYPE_ENUM, TYPE_GL, GL_FUNC)                              \
    template <GLsizei SIZE = 1>                                                         \
    class Uniform##TYPE_ENUM : public UniformObject {                                   \
    public:                                                                             \
        explicit Uniform##TYPE_ENUM(GLint location = kInvalidLocation)                  \
            : UniformObject(location) {}                                                \
        Uniform##TYPE_ENUM(const Program& program,                                      \
                           const char* qualifier)                                       \
            : UniformObject(program, qualifier) {}                                      \
        void set(const TYPE_GL* value, Boolean transpose = Boolean::False) {           \
            if (this->isValid()) {                                                      \
                GL_FUNC(location_, SIZE, static_cast<GLboolean>(transpose), value);     \
            }                                                                           \
        }                                                                               \
    };

    DEFINE_UNIFORM(Int, GLint, glUniform1iv)

    DEFINE_UNIFORM(Uint, GLuint, glUniform1uiv)

    DEFINE_UNIFORM(Float, GLfloat, glUniform1fv)

    DEFINE_UNIFORM(Double, GLdouble, glUniform1dv)

    DEFINE_UNIFORM(Vec2, GLfloat, glUniform2fv)

    DEFINE_UNIFORM(Vec3, GLfloat, glUniform3fv)

    DEFINE_UNIFORM(Vec4, GLfloat, glUniform4fv)

    DEFINE_UNIFORM(IVec2, GLint, glUniform2iv)

    DEFINE_UNIFORM(IVec3, GLint, glUniform3iv)

    DEFINE_UNIFORM(IVec4, GLint, glUniform4iv)

    DEFINE_UNIFORM(UVec2, GLuint, glUniform2uiv)

    DEFINE_UNIFORM(UVec3, GLuint, glUniform3uiv)

    DEFINE_UNIFORM(UVec4, GLuint, glUniform4uiv)

    DEFINE_UNIFORM(DVec2, GLdouble, glUniform2dv)

    DEFINE_UNIFORM(DVec3, GLdouble, glUniform3dv)

    DEFINE_UNIFORM(DVec4, GLdouble, glUniform4dv)

    DEFINE_MATRIX_UNIFORM(Mat2, GLfloat, glUniformMatrix2fv)

    DEFINE_MATRIX_UNIFORM(Mat3, GLfloat, glUniformMatrix3fv)

    DEFINE_MATRIX_UNIFORM(Mat4, GLfloat, glUniformMatrix4fv)

    DEFINE_MATRIX_UNIFORM(Mat2x3, GLfloat, glUniformMatrix2x3fv)

    DEFINE_MATRIX_UNIFORM(Mat3x2, GLfloat, glUniformMatrix3x2fv)

    DEFINE_MATRIX_UNIFORM(Mat2x4, GLfloat, glUniformMatrix2x4fv)

    DEFINE_MATRIX_UNIFORM(Mat4x2, GLfloat, glUniformMatrix4x2fv)

    DEFINE_MATRIX_UNIFORM(Mat3x4, GLfloat, glUniformMatrix3x4fv)

    DEFINE_MATRIX_UNIFORM(Mat4x3, GLfloat, glUniformMatrix4x3fv)

    DEFINE_MATRIX_UNIFORM(DMat2, GLdouble, glUniformMatrix2dv)

    DEFINE_MATRIX_UNIFORM(DMat3, GLdouble, glUniformMatrix3dv)

    DEFINE_MATRIX_UNIFORM(DMat4, GLdouble, glUniformMatrix4dv)

    DEFINE_MATRIX_UNIFORM(DMat2x3, GLdouble, glUniformMatrix2x3dv)

    DEFINE_MATRIX_UNIFORM(DMat3x2, GLdouble, glUniformMatrix3x2dv)

    DEFINE_MATRIX_UNIFORM(DMat2x4, GLdouble, glUniformMatrix2x4dv)

    DEFINE_MATRIX_UNIFORM(DMat4x2, GLdouble, glUniformMatrix4x2dv)

    DEFINE_MATRIX_UNIFORM(DMat3x4, GLdouble, glUniformMatrix3x4dv)

    DEFINE_MATRIX_UNIFORM(DMat4x3, GLdouble, glUniformMatrix4x3dv)

#undef DEFINE_UNIFORM
#undef DEFINE_MATRIX_UNIFORM
}
