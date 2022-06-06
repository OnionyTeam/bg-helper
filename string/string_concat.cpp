#include "string_concat.hpp"
#include "core.hpp"
#include "to_string.hpp"

namespace bg_helper {

    template<Character char_type = bg_helper::char_type, typename... Args>
    [[nodiscard]] std::basic_string<char_type> connect(const Args &...v) {
        std::basic_string<char_type> buffer;
        std::size_t size {};
        ((size += std::basic_string_view<char_type>(v).size()), ...);
        buffer.reserve(size);
        ((buffer += std::basic_string_view<char_type>(v)), ...);
        return buffer;
    }

    template<Character char_type = bg_helper::char_type, typename... Args>
    [[nodiscard]] std::basic_string<char_type> concat(const Args &...v) {
        return connect<char_type>(to_string<char_type>(v)...);
    }
} // bg_helper
