#ifndef _BGHELPER_CORE_H
#define _BGHELPER_CORE_H

#include <type_traits>
#include <concepts>
#include <string>

namespace bg_helper {

#ifdef UNICODE
    using char_type = wchar_t;
#else
    using char_type = char;
#endif

    // const value
    constexpr std::string_view CONTAINER_START_SYMBOL = "[";
    constexpr std::string_view CONTAINER_END_SYMBOL = "]";
    constexpr std::string_view CONTAINER_SPLIT_SYMBOL = ", ";
    constexpr std::wstring_view CONTAINER_START_SYMBOL_L = L"[";
    constexpr std::wstring_view CONTAINER_END_SYMBOL_L = L"]";
    constexpr std::wstring_view CONTAINER_SPLIT_SYMBOL_L = L", ";

    template<typename T>
    concept Character = std::is_same_v<T, char> || std::is_same_v<T, wchar_t>;
    
    template<typename T>
    concept Float = std::is_floating_point_v<T>;

    template<typename T>
    concept Boolean = std::is_same_v<bool, std::decay_t<T>>;
    
    template<typename T> concept String = 
        std::is_same_v<T, std::string> || std::is_same_v<T, std::wstring> ||
        std::is_same_v<T, std::string_view> || std::is_same_v<T, std::wstring_view>;
} // bg_helper

#endif //_BGHELPER_CORE_H
