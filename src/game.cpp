#include "bw/engine/game.h"

#include "bw/engine/fps_counter.h"
#include "bw/engine/input.h"
#include "bw/engine/time_manager.h"


namespace bw::engine {
    Game::Game(Application& application, Engine& engine)
        : application_(application),
          engine_(engine),
          window_(application_.getWindow()) {
        window_.keyEvent.set(
            [](const glfw::KeyCode key, int, const glfw::KeyAction action, glfw::ModifierKeyBit) {
                Input::HandleKey(key, action);
            });
        window_.mouseButtonEvent.set(
            [](const glfw::MouseButton mouse_button, const glfw::MouseButtonAction action, glfw::ModifierKeyBit) {
                Input::HandleMouseButton(mouse_button, action);
            });
        window_.framebufferSizeEvent.set(
            [this](const int width, const int height) {
                glad::Viewport(width, height);
            });
        window_.cursorPosEvent.set(
            [](const double x, const double y) {
                Input::HandleCursorPosition(static_cast<float>(x), static_cast<float>(y));
            });
        window_.scrollEvent.set(
            [](const double x, const double y) {
                Input::HandleScroll(static_cast<float>(x), static_cast<float>(y));
            });
    }

    Game::~Game() = default;

    void Game::init() {
        for (const auto& gameObject : gameObjects_) {
            gameObject->init();
        }
    }


    void Game::run() {
        TimeManager timeManager;
        FPSCounter fpsCounter;

        while (!window_.shouldClose()) {
            glfwPollEvents();
            Input::Update();

            const auto deltaTime = timeManager.getDeltaTime();
            fpsCounter.update();

            update(deltaTime);
            render();

            if (Input::GetKeyDown(glfw::KeyCode::Escape)) {
                window_.setShouldClose(true);
            }

            window_.swapBuffers();
        }
    }

    void Game::update(const float deltaTime) {
        for (const auto& gameObject : gameObjects_) {
            gameObject->update(deltaTime);
        }
    }

    void Game::render() {
        glad::ClearBuffers().Color().Depth();
        glad::ClearColor(0.1f, 0.4f, 0.7f);

        for (const auto& gameObject : gameObjects_) {
            gameObject->render(*camera_);
        }
    }
}
