#ifndef _BGHELPER_TO_STRING_H__
#define _BGHELPER_TO_STRING_H__

#include "core.hpp"
#include "milo/dtoa_milo.h"
#include "string_concat.hpp"
#include <iomanip>
#include <ranges>
#include <string>
#include <type_traits>
#include <vector>

namespace bg_helper {

template <Character char_type_t, typename T>
std::basic_string<char_type_t> quoted_if_string(const T &value);

template <Character char_type_t, typename T>
constexpr std::basic_string<char_type_t> to_string(const T &value);

template <Character char_type_t = bg_helper::char_type,
          std::convertible_to<std::basic_string_view<char_type_t>> T>
constexpr std::basic_string<char_type_t> _to_string(const T &value) noexcept {
    return std::basic_string<char_type_t>(value);
}

template <Character char_type_t = bg_helper::char_type, has_to_string T>
constexpr std::basic_string<char_type_t> _to_string(T &t) noexcept {
    return t.to_string();
}

template <Character char_type_t = bg_helper::char_type, std::integral T,
          typename = std::enable_if_t<!Boolean<T> && !Character<T>,
                                      std::basic_string<char_type_t>>>
constexpr std::basic_string<char_type_t> _to_string(const T &value) noexcept {
    if constexpr (std::is_same_v<wchar_t, char_type_t>) {
        return std::to_wstring(value);
    } else {
        return std::to_string(value);
    }
}
template <Character char_type_t = bg_helper::char_type>
constexpr std::basic_string<char_type_t>
_to_string(const char_type_t &value) noexcept {
    char_type_t c[2]{value, 0};
    return std::basic_string<char_type_t>(c);
}

template <Character char_type_t = bg_helper::char_type>
constexpr std::basic_string<char_type_t>
_to_string(const float &value) noexcept {
    if constexpr (std::is_same_v<wchar_t, char_type_t>) {
        return std::to_wstring(value);
    } else {
        return std::to_string(value);
    }
}

template <Character char_type_t = bg_helper::char_type, typename T, size_t N>
[[nodiscard]] std::enable_if_t<!String<T>, std::basic_string<char_type_t>>
_to_string(const T (&arr)[N]) {
    std::basic_string<char_type_t> buff;
    buff.append(square_brakets<char_type_t>(0));
    for (size_t i = 0; i < N - 1; ++i) {
        buff.append(to_string<char_type_t>(arr[i]));
        buff.append(comma<char_type_t>());
    }
    buff.append(to_string<char_type_t>(arr[N - 1]));
    buff.append(square_brakets<char_type_t>(1));
    return buff;
}

template <Character char_type_t = bg_helper::char_type, typename T, typename E>
constexpr std::basic_string<char_type_t>
_to_string(const std::pair<T, E> &value,
           const std::basic_string_view<char_type_t> &split_c =
               comma<char_type_t>()) noexcept {
    return bg_helper::connect<char_type_t>(
        brakets(0), quoted_if_string<char_type_t>(value.first), split_c,
        quoted_if_string<char_type_t>(value.second), brakets(1));
}

template <Character char_type_t = bg_helper::char_type>
constexpr std::basic_string<char_type_t>
_to_string(const double &value) noexcept {
    if constexpr (std::is_same_v<wchar_t, char_type_t>) {
        return std::to_wstring(value);
    } else {
        char buff[50];
        dtoa_milo(value, buff);
        return std::string(buff);
    }
}

template <Character char_type_t = bg_helper::char_type, Boolean T>
constexpr std::basic_string<char_type_t> _to_string(const T value) noexcept {
    return true_false<char_type_t>(value);
}

template <Character char_type_t = bg_helper::char_type, Map T>
std::basic_string<char_type_t> _to_string(const T &value) noexcept {
    std::basic_string<char_type_t> buffer;
    auto size = value.size();
    if (size > 10) {
        buffer.reserve(size * 3);
    }
    buffer.append(curly_braces<char_type_t>(0));
    for (auto &&e : value) {
        buffer.append(quoted_if_string<char_type_t>(e.first));
        buffer.append(colon<char_type_t>());
        buffer.append(quoted_if_string<char_type_t>(e.second));
        buffer.append(comma<char_type_t>());
    }
    if (size > 0)
        buffer.erase(buffer.size() - comma<char_type_t>().size());
    buffer.append(curly_braces<char_type_t>(1));
    return buffer;
}

template <Character char_type_t = bg_helper::char_type, std::ranges::range T>
[[nodiscard]] std::enable_if_t<!String<T> && !Map<T>,
                               std::basic_string<char_type_t>>
_to_string(const T &value) noexcept {
    std::basic_string<char_type_t> buffer;
    auto size = value.size();
    if (size > 10) {
        buffer.reserve(size * 3);
    }
    buffer.append(square_brakets<char_type_t>(0));
    for (auto &&e : value) {
        buffer.append(quoted_if_string<char_type_t>(e));
        buffer.append(comma<char_type_t>());
    }
    if (size > 0)
        buffer.erase(buffer.size() - comma<char_type_t>().size());
    buffer.append(square_brakets<char_type_t>(1));
    return buffer;
}

template <Character char_type_t, typename T, size_t N> struct tuple_to_string {
    static void to_string(const T &tup, std::basic_string<char_type_t> &buff);
};

template <Character char_type_t, typename T>
struct tuple_to_string<char_type_t, T, 1> {
    static void to_string(const T &tup, std::basic_string<char_type_t> &buff);
};

template <Character char_type_t = bg_helper::char_type, typename... Args>
[[nodiscard]] __attribute__((
    always_inline)) inline std::basic_string<char_type_t>
_to_string(const std::tuple<Args...> &value) {
    constexpr size_t size = sizeof...(Args);
    static_assert(size < 10, "too large tuple!!!");
    std::basic_string<char_type_t> buff;
    buff.append(brakets<char_type_t>(0));
    tuple_to_string<char_type_t, decltype(value), size>::to_string(value, buff);
    buff.append(brakets<char_type_t>(1));
    return buff;
}

template <Character char_type_t, typename T, size_t N>
void tuple_to_string<char_type_t, T, N>::to_string(
    const T &tup, std::basic_string<char_type_t> &buff) {
    tuple_to_string<char_type_t, T, N - 1>::to_string(tup, buff);
    buff.append(comma<char_type_t>());
    buff.append(bg_helper::quoted_if_string<char_type_t>(std::get<N - 1>(tup)));
}

template <Character char_type_t, typename T>
void tuple_to_string<char_type_t, T, 1>::to_string(
    const T &tup, std::basic_string<char_type_t> &buff) {
    buff.append(bg_helper::quoted_if_string<char_type_t>(std::get<0>(tup)));
}

template <typename char_type_t, typename T>
concept convertible = requires(T& a) {
    bg_helper::_to_string<char_type_t>(a);
};

template <Character char_type_t = bg_helper::char_type>
constexpr std::basic_string<char_type> &&
_to_string(std::basic_string<char_type_t> &&value) noexcept {
    return std::forward<std::basic_string<char_type_t> &&>(value);
}

template <Character char_type_t = bg_helper::char_type, typename T>
constexpr std::basic_string<char_type_t> to_string(const T &value) {
    constexpr bool ok = convertible<char_type_t, T>;
    if constexpr (ok) {
        return _to_string<char_type_t>(value);
    } else {
        // error
        static_assert(ok, "some types could not convert");
        return comma<char_type_t>();
    }
}

template <Character char_type_t = bg_helper::char_type, typename T>
std::basic_string<char_type_t> inline quoted_if_string(const T &value) {
    if constexpr (String<T>) {
        return bg_helper::quoted<char_type_t>(
            bg_helper::to_string<char_type_t>(value));
    }
    if constexpr (std::is_same_v<char_type_t, T>) {
        char_type_t arr[2]{value, 0};
        return bg_helper::quoted<char_type_t>(
            std::basic_string<char_type_t>(arr), quotes());
    }
    return bg_helper::to_string<char_type_t>(value);
}

template <Character char_type_t = bg_helper::char_type, typename... Args>
constexpr std::basic_string<char_type_t> concat(const Args &...v) {
    return connect<char_type_t>(to_string<char_type_t>(v)...);
}

} // namespace bg_helper

#endif //_BGHELPER_TO_STRING_H__
