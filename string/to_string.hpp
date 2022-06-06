#ifndef _BGHELPER_TO_STRING_H
#define _BGHELPER_TO_STRING_H

#include "core.hpp"
#include <string>

namespace bg_helper {
    template<Character char_type = bg_helper::char_type,
        std::convertible_to<std::basic_string_view<char_type>> T>
    [[nodiscard]] inline std::basic_string<char_type> to_string(const T &value) noexcept {
        return std::basic_string<char_type> { value };
    }

    template<Character char_type = bg_helper::char_type,
        Float T>
    [[nodiscard]] inline std::basic_string<char_type> to_string(const T value) noexcept {
        if constexpr (std::is_same_v<wchar_t, T>) {
            return std::to_wstring(value);
        } else {
            return std::to_string(value);
        }
    }

    template<Character char_type = bg_helper::char_type,
        std::integral T, typename = std::enable_if_t<!Boolean<T>, std::basic_string<char_type>>>
    [[nodiscard]] inline std::basic_string<char_type> to_string(const T value) noexcept {
        if constexpr (std::is_same_v<wchar_t, T>) {
            return std::to_wstring(value);
        } else {
            return std::to_string(value);
        }
    }

    template<Character char_type = bg_helper::char_type,
        Boolean T>
    [[nodiscard]] inline std::basic_string<char_type> to_string(const T value) noexcept {
        if constexpr (std::is_same_v<wchar_t, T>) {
            return value ? L"True" : L"False";
        } else {
            return value ? "True" : "False";
        }
        
    }

    template<Character char_type = bg_helper::char_type,
        Iterable T>
    [[nodiscard]] inline 
    std::enable_if_t<!String<T>, std::basic_string<char_type>>
    to_string(const T &value) noexcept {
        auto func = [&](const char_type START_SYMBOL, const char_type END_SYMBOL, const char_type SPLIT_CHAR) {
            std::basic_string<char_type> buffer;
            buffer.push_back(START_SYMBOL);
            for (auto &&e : value) {
                buffer.append(to_string<char_type>(e));
                buffer.push_back(SPLIT_CHAR);
            }
            buffer.pop_back();
            buffer.push_back(END_SYMBOL);
            return buffer;
        };
        if constexpr (std::is_same_v<wchar_t, T>) {
            return func(L'[', L']', L',');
        } else {
            return func('[', ']', ',');
        }
    }



} // bg_helper

#endif //_BGHELPER_TO_STRING_H
