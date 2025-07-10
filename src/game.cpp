#include "bw/engine/game.h"

#include "bw/engine/fps_counter.h"
#include "bw/engine/input.h"
#include "bw/engine/time_manager.h"


namespace bw::engine {
    auto renderTargetVertexShaderSource = R"(
#version 330 core
layout (location = 0) in vec2 aPos;
layout (location = 1) in vec2 aTexCoords;

out vec2 TexCoords;

void main()
{
    TexCoords = aTexCoords;
    gl_Position = vec4(aPos.x, aPos.y, 0.0, 1.0);
})";

    auto renderTargetFragmentShaderSource = R"(
#version 330 core
out vec4 FragColor;

in vec2 TexCoords;

uniform sampler2D screenTexture;

void main()
{
    vec3 col = texture(screenTexture, TexCoords).rgb;
    FragColor = vec4(col, 1.0);
    //FragColor = vec4(TexCoords.x, TexCoords.y, 0.0, 1.0);
})";

    struct RenderTargetVertex {
        glm::vec2 position;
        glm::vec2 uv;
    };

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
                update_render_target(width, height);
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
        int w_width, w_height;
        window_.getWindowSize(&w_width, &w_height);
        init_render_target(w_width, w_height);

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
        }
    }

    void Game::init_render_target(const int width, const int height) {
        glad::Bind(m_framebuffer);

        const std::vector<RenderTargetVertex> vertices{
            {{-1.0f, 1.0f}, {0.0f, 1.0f}}, // Left-Top
            {{-1.0f, -1.0f}, {0.0f, 0.0f}}, // Left-Bottom
            {{1.0f, -1.0f}, {1.0f, 0.0f}}, // Right-Bottom
            {{1.0f, 1.0f}, {1.0f, 1.0f}} // Right-Top
        };

        const std::vector<GLuint> indices{
            0, 1, 2, // Left-Bottom triangle
            0, 2, 3 // Right-Top triangle
        };

        glad::Bind(m_vao);
        m_vbo.data(sizeof(RenderTargetVertex) * vertices.size(), vertices.data());
        m_ebo.data(sizeof(GLuint) * indices.size(), indices.data());
        m_indicesCount = static_cast<GLsizei>(indices.size());

        glad::VertexAttribute(0)
            .pointer(2,
                     glad::DataType::Float,
                     false,
                     sizeof(RenderTargetVertex))
            .enable();
        glad::VertexAttribute(1)
            .pointer(2,
                     glad::DataType::Float,
                     false,
                     sizeof(RenderTargetVertex),
                     reinterpret_cast<void*>(offsetof(RenderTargetVertex, uv)))
            .enable();

        auto vertexShader = glad::VertexShader();
        vertexShader.set_source(renderTargetVertexShaderSource);

        auto fragmentShader = glad::FragmentShader();
        fragmentShader.set_source(renderTargetFragmentShaderSource);

        m_shaderProgram.attach_shader(vertexShader, fragmentShader);
        m_shaderProgram.link();

        glad::Bind(m_texture);
        m_texture.upload(0,
                         glad::PixelDataInternalFormat::RGB,
                         width, height,
                         glad::PixelDataFormat::BGR,
                         glad::PixelDataType::UnsignedByte,
                         nullptr);
        m_texture.minFilter(glad::MinFilter::Nearest);
        m_texture.magFilter(glad::MagFilter::Nearest);

        m_framebuffer.attach(glad::FramebufferTarget::Framebuffer,
                             glad::FramebufferAttachment::ColorAttachment0,
                             m_texture);

        glad::Bind(m_renderbuffer);
        m_renderbuffer.storage(glad::PixelDataInternalFormat::Depth24Stencil8, width, height);
        m_framebuffer.attach(glad::FramebufferTarget::Framebuffer,
                             glad::FramebufferAttachment::DepthStencilAttachment,
                             m_renderbuffer);

        glad::Unbind(m_framebuffer);
    }

    void Game::update_render_target(const int width, const int height) {
        glad::Bind(m_texture);
        m_texture.upload(0,
                         glad::PixelDataInternalFormat::RGB,
                         width, height,
                         glad::PixelDataFormat::BGR,
                         glad::PixelDataType::UnsignedByte,
                         nullptr);

        glad::Bind(m_renderbuffer);
        m_renderbuffer.storage(glad::PixelDataInternalFormat::Depth24Stencil8, width, height);

    }

    void Game::update(const float deltaTime) {
        for (const auto& gameObject : gameObjects_) {
            gameObject->update(deltaTime);
        }
    }

    void Game::render() {
        int w_width, w_height;
        window_.getWindowSize(&w_width, &w_height);

        glad::Bind(m_framebuffer);

        glad::Viewport(w_width, w_height);
        glad::Enable(glad::Capability::DepthTest);
        glad::Enable(glad::Capability::CullFace);
        glad::ClearColor(0.1f, 0.4f, 0.7f);
        glad::ClearBuffers().Color().Depth();

        for (const auto& gameObject : gameObjects_) {
            gameObject->render(*camera_);
        }

        glad::Unbind(m_framebuffer);


        glad::Disable(glad::Capability::DepthTest);

        glad::Viewport(w_width, w_height);
        glad::ClearBuffers().Color();

        glad::Bind(m_shaderProgram);
        glad::Bind(m_vao);
        glad::Bind(m_texture);
        constexpr int texture_unit = 0;
        glad::UniformInt(m_shaderProgram, "screenTexture").set(&texture_unit);
        glad::DrawElements(glad::PrimitiveType::Triangles, 6, glad::IndexType::UnsignedInt);

        window_.swapBuffers();
    }
}
