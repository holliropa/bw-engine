#pragma once

#include "gl.h"
#include "glm.h"

namespace bw::engine {
    class Input {
    public:
        static void InitCursor(float x, float y);

        static bool GetKeyPressed(glfw::KeyCode code);
        static bool GetKeyDown(glfw::KeyCode code);
        static bool GetKeyUp(glfw::KeyCode code);

        static bool GetMouseButtonPressed(glfw::MouseButton button);
        static bool GetMouseButtonDown(glfw::MouseButton button);
        static bool GetMouseButtonUp(glfw::MouseButton button);

        static const glm::vec2& GetCursorPosition();
        static const glm::vec2& GetCursorOffset();

        static const glm::vec2& GetScrollOffset();

        static void HandleKey(glfw::KeyCode code, glfw::KeyAction action);
        static void HandleMouseButton(glfw::MouseButton button, glfw::MouseButtonAction action);
        static void HandleCursorPosition(float x, float y);
        static void HandleScroll(float x, float y);

        static void Update();
        static void Clear();
    };
}
