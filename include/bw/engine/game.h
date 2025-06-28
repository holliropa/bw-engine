#pragma once

#include "application.h"
#include "engine.h"
#include "game_object.h"

namespace bw::engine {
    class Game {
    protected:
        Application& application_;
        Engine& engine_;
        glfw::Window& window_;
        std::vector<std::shared_ptr<GameObject>> gameObjects_;
        std::shared_ptr<Camera> camera_;

    public:
        Game(Application& application, Engine& engine);

        ~Game();

        void init();

        void run();

    private:
        void update(float deltaTime);
        void render();
    };
}
