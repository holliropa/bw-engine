#pragma once

#include <utility>

namespace glad {
    class Handle {
    public:
        explicit operator GLuint() const { return handle_; }

        Handle(const Handle&) = delete;

        Handle& operator=(const Handle&) = delete;

        Handle(Handle&& other) noexcept
            : handle_{other.handle_},
              ownership_{other.ownership_} {
            other.handle_ = 0;
            other.ownership_ = false;
        }

        Handle& operator=(Handle&& other) noexcept {
            handle_ = std::exchange(other.handle_, 0);
            ownership_ = std::exchange(other.ownership_, false);

            return *this;
        }

        virtual ~Handle() = default;

        [[nodiscard]] bool hasOwnership() const { return ownership_; }

    protected:
        GLuint handle_ = 0;
        bool ownership_ = false;

        Handle() = default;
    };
}
