#pragma once

#include "application.h"
#include "engine.h"
#include "base_object.h"

namespace bw::engine {
    class Game {
    protected:
        Application& application_;
        Engine& engine_;
        glfw::Window& window_;
        std::vector<std::shared_ptr<BaseObject>> gameObjects_;
        std::shared_ptr<Camera> camera_;

        glad::Framebuffer m_framebuffer;
        glad::Texture2D m_colorBufferTexture;
        glad::Renderbuffer m_renderbuffer;

        glad::VertexArray m_vao;
        glad::ArrayBuffer m_vbo;
        glad::ElementArrayBuffer m_ebo;
        GLsizei m_indicesCount{};
        glad::Program m_shaderProgram;
        glad::Texture2D m_texture;

    public:
        Game(Application& application, Engine& engine);

        ~Game();

        void init();

        void run();

    private:
        void init_render_target(int width, int height);
        void update_render_target(int width, int height);

        void update(float deltaTime);
        void render();
    };
}
