#ifndef BGHELPER_OUTPUT_H__
#define BGHELPER_OUTPUT_H__

#include <stdio.h>
#include "string_concat.hpp"

namespace bg_helper {

    template<Character char_type = bg_helper::char_type,
        typename ...Args>
    void print(const Args& ...v) {
        const auto buffer = concat<char_type>(v...);
        if constexpr (std::is_same_v<char_type, char>) {
            printf("%s", buffer.c_str());
        } else {
            wprintf(L"%s", buffer.c_str());
        }
    }

    template<typename ...Args>
    void println(const Args& ...v) {
        if constexpr (std::is_same_v<char_type, char>) {
            const auto buffer = concat<char_type>(v...);
            printf("%s\n", buffer.c_str());
        } else {
            const auto buffer = concat<char_type>(v...);
            wprintf(L"%s\n", buffer.c_str());
        }
    }

} // bg_helper

#endif // BGHELPER_OUTPUT_H__
