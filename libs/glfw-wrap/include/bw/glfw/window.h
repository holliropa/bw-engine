#pragma once

#include "event.h"
#include "enums/key_code.h"
#include "enums/key_action.h"
#include "enums/modifier_key_bit.h"
#include "enums/mouse_button.h"
#include "enums/mouse_button_action.h"
#include "enums/cursor_mode.h"

namespace
glfw {
    class Window {
        GLFWwindow* window;

        static Window& _getWrapperFromHandle(GLFWwindow* handle_) {
            return *static_cast<Window*>(glfwGetWindowUserPointer(handle_));
        }

        static void _framebufferSizeCallback(GLFWwindow* window_,
                                             const int width_,
                                             const int height_
        ) {
            _getWrapperFromHandle(window_)
                .framebufferSizeEvent(width_, height_);
        }

        static void _keyCallback(GLFWwindow* window_,
                                 const int key,
                                 const int scancode,
                                 const int action,
                                 const int mods
        ) {
            _getWrapperFromHandle(window_)
                .keyEvent(static_cast<KeyCode>(key),
                          scancode,
                          static_cast<KeyAction>(action),
                          static_cast<ModifierKeyBit>(mods));
        }

        static void _cursorPosCallback(GLFWwindow* window_,
                                       const double x,
                                       const double y
        ) {
            _getWrapperFromHandle(window_)
                .cursorPosEvent(x, y);
        }

        static void _mouseButtonCallback(GLFWwindow* window_,
                                         const int button,
                                         const int action,
                                         const int mods
        ) {
            _getWrapperFromHandle(window_)
                .mouseButtonEvent(static_cast<MouseButton>(button),
                                  static_cast<MouseButtonAction>(action),
                                  static_cast<ModifierKeyBit>(mods));
        }

        static void _cursorEnterCallback(GLFWwindow* window_,
                                         const int enter
        ) {
            _getWrapperFromHandle(window_)
                .cursorEnterEvent(static_cast<bool>(enter));
        }

        static void _scrollCallback(GLFWwindow* window_,
                                    const double x,
                                    const double y
        ) {
            _getWrapperFromHandle(window_)
                .scrollEvent(x, y);
        }

    public:
        Event<int, int> framebufferSizeEvent;
        Event<KeyCode, int, KeyAction, ModifierKeyBit> keyEvent;
        Event<double, double> cursorPosEvent;
        Event<MouseButton, MouseButtonAction, ModifierKeyBit> mouseButtonEvent;
        Event<bool> cursorEnterEvent;
        Event<double, double> scrollEvent;

        Window(const int width,
               const int height,
               const char* title,
               GLFWmonitor* monitor = nullptr,
               GLFWwindow* share = nullptr) {
            window = glfwCreateWindow(width, height, title, monitor, share);

            glfwSetWindowUserPointer(window, this);

            glfwSetFramebufferSizeCallback(window, _framebufferSizeCallback);
            glfwSetKeyCallback(window, _keyCallback);
            glfwSetCursorPosCallback(window, _cursorPosCallback);
            glfwSetMouseButtonCallback(window, _mouseButtonCallback);
            glfwSetCursorEnterCallback(window, _cursorEnterCallback);
            glfwSetScrollCallback(window, _scrollCallback);
        }

        ~Window() {
            glfwDestroyWindow(window);
        }

        [[nodiscard]] bool isValid() const {
            return window;
        }

        [[nodiscard]] bool shouldClose() const {
            return glfwWindowShouldClose(window);
        }

        void setShouldClose(const bool value) {
            glfwSetWindowShouldClose(window, value);
        }

        void swapBuffers() {
            glfwSwapBuffers(window);
        }

        void setTitle(const char* title_) {
            glfwSetWindowTitle(window, title_);
        }

        void setSwapInterval(const int interval) {
            glfwSwapInterval(interval);
        }

        void setCursorMode(CursorMode mode) const {
            glfwSetInputMode(window, GLFW_CURSOR, static_cast<int>(mode));
        }

        void getCursorPosition(double* x, double* y) const {
            glfwGetCursorPos(window, x, y);
        }

        void setCursorPosition(const double x, const double y) const {
            glfwSetCursorPos(window, x, y);
        }

        void getWindowSize(int* width, int* height) {
            glfwGetWindowSize(window, width, height);
        }

        explicit operator GLFWwindow*() const {
            return window;
        }
    };
}
