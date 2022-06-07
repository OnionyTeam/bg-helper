#ifndef _BGHELPER_STRING_CONCAT_H__
#define _BGHELPER_STRING_CONCAT_H__

#include "core.hpp"
#include <string>
#include <string_view>

namespace bg_helper {

    /**
     * Summary: connect strings
     * Paramters:
     *     v: strings to concatenate
     * Example:
     *     connect("A", "B", "C") --> "ABC"
     */
    template<Character char_type = bg_helper::char_type, typename... Args>
    [[nodiscard]] std::basic_string<char_type> connect(const Args &...v) {
        std::basic_string<char_type> buffer;
        std::size_t size {};
        ((size += std::basic_string_view<char_type>(v).size()), ...);
        buffer.reserve(size);
        ((buffer += std::basic_string_view<char_type>(v)), ...);
        return buffer;
    }

    /**
     * Summary: connect elements to string
     * Paramters:
     *     v: elements to concatenate
     * Example:
     *     concat("PI = ", 3.1415) --> "PI = 3.1415"
     */
    template<Character char_type = bg_helper::char_type, typename... Args>
    [[nodiscard]] std::basic_string<char_type> concat(const Args &...v) {
        return connect<char_type>(to_string<char_type>(v)...);
    }
    
} // bg_helper

#endif //_BGHELPER_STRING_CONCAT_H__
