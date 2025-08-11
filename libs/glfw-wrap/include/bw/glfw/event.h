#pragma once

#include <functional>

namespace glfw {
    template <typename... Args>
    class Event {
        std::vector<std::pair<size_t, std::function<void(Args...)>>> _handlers;
        size_t _next_id = 0;

    public:
        template <typename Callback>
        size_t set(Callback&& callback_) {
            size_t id = _next_id++;
            _handlers.emplace_back(id, std::forward<Callback>(callback_));
            return id;
        }

        bool unregister(size_t handle) {
            auto it = std::find_if(_handlers.begin(), _handlers.end(),
                [handle](const auto& pair) { return pair.first == handle; });

            if (it != _handlers.end()) {
                _handlers.erase(it);
                return true;
            }
            return false;
        }

        void operator()(Args... args_) {
            for (const auto& [id, handler] : _handlers) {
                handler(args_...);
            }
        }
    };
}
