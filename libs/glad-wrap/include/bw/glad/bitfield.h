#pragma once


namespace glad {
    template <typename Bit>
    class Bitfield {
    public:
        Bitfield() : bits_{0} {}

        explicit Bitfield(const GLbitfield bits) : bits_(bits) {}

        explicit Bitfield(Bit bit) : bits_(static_cast<GLbitfield>(bit)) {}

        Bitfield operator|(Bit b) const {
            return Bitfield{bits_ | static_cast<GLbitfield>(b)};
        }

        Bitfield operator|(const Bitfield& other) {
            return Bitfield{bits_ | other.bits_};
        }

        Bitfield& operator|=(Bit b) {
            bits_ |= static_cast<GLbitfield>(b);
            return *this;
        }

        Bitfield& operator|=(const Bitfield& other) {
            bits_ |= other.bits_;
            return *this;
        }

        explicit operator GLbitfield() const { return bits_; }

    private:
        GLbitfield bits_;
    };
}
