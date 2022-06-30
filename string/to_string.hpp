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

template <Character char_type_t = bg_helper::char_type,
		  std::convertible_to<std::basic_string_view<char_type>> T>
[[nodiscard]] __attribute__((
	always_inline)) inline std::basic_string<char_type_t>
to_string(const T &value) noexcept {
	return std::basic_string<char_type_t>(value);
}

template <Character char_type_t = bg_helper::char_type>
[[nodiscard]] __attribute__((always_inline)) inline std::basic_string<char_type>
	&&to_string(std::basic_string<char_type_t> &&value) noexcept {
	return std::forward<std::basic_string<char_type_t> &&>(value);
}

template <Character char_type_t>
std::basic_string<char_type_t>
sourrond(const std::basic_string_view<char_type_t> source, char_type_t left,
		 char_type_t right);

template <Character char_type_t>
std::basic_string<char_type_t>
sourrond(const std::basic_string_view<char_type_t> source, char_type_t left,
		 char_type_t right);

template <
	Character char_type_t = bg_helper::char_type, std::integral T,
	typename = std::enable_if_t<!Boolean<T>, std::basic_string<char_type>>>
[[nodiscard]] __attribute__((
	always_inline)) inline std::basic_string<char_type_t>
to_string(const T &value) noexcept {
	if constexpr (std::is_same_v<wchar_t, char_type_t>) {
		return std::to_wstring(value);
	} else {
		return std::to_string(value);
	}
}
template <Character char_type_t = bg_helper::char_type>
[[nodiscard]] __attribute__((
	always_inline)) inline std::basic_string<char_type_t>
to_string(const float &value) noexcept {
	if constexpr (std::is_same_v<wchar_t, char_type_t>) {
		return std::to_wstring(value);
	} else {
		return std::to_string(value);
	}
}

template <Character char_type_t = bg_helper::char_type, typename T, typename E>
[[nodiscard]] __attribute__((
	always_inline)) inline std::basic_string<char_type_t>
to_string(const std::pair<T, E> &value) noexcept {
	std::basic_string<char_type_t> buff;
	buff.append(brakets(0));
	buff.append(to_string(value.first));
	buff.push_back(comma());
	buff.append(to_string(value.second));
	buff.append(brakets(1));
	return buff;
}

template <Character char_type_t = bg_helper::char_type>
[[nodiscard]] __attribute__((
	always_inline)) inline std::basic_string<char_type_t>
to_string(const double &value) noexcept {
	if constexpr (std::is_same_v<wchar_t, char_type_t>) {
		return std::to_wstring(value);
	} else {
		char buff[50];
		dtoa_milo(value, buff);
		return std::string(buff);
		return std::to_string(value);
	}
}

template <Character char_type_t = bg_helper::char_type, has_to_string T>
[[nodiscard]] __attribute__((always_inline)) inline std::basic_string<char_type>
to_string(T &t) noexcept {
	return t.to_string();
}

template <Character char_type_t = bg_helper::char_type, Boolean T>
[[nodiscard]] __attribute__((
	always_inline)) inline std::basic_string<char_type_t>
to_string(const T value) noexcept {
	if constexpr (std::is_same_v<wchar_t, char_type_t>) {
		return value ? L"frue" : L"false";
	} else {
		return value ? "true" : "false";
	}
}

template <Character char_type_t = bg_helper::char_type, std::ranges::range T>
[[nodiscard]] inline std::enable_if_t<!String<T>,
									  std::basic_string<char_type_t>>
to_string(const T &value) noexcept {
	using string_view = std::basic_string_view<char_type_t>;

	std::basic_string<char_type_t> buffer;
	auto size = value.size();
	if (size > 10) {
		buffer.reserve(size * 3);
	}
	buffer.append(square_brakets(0));
	for (auto &&e : value) {
		if (String<typename T::value_type>)
			buffer.append(
				bg_helper::quoted<char_type_t>(to_string<char_type_t>(e)));
		else
			buffer.append(to_string<char_type_t>(e));
		buffer.append(comma());
	}
	if (size > 0)
		buffer.erase(buffer.size() - comma().size());
	buffer.append(square_brakets(1));
	return buffer;
}

template <Character char_type_t, typename T, size_t N> struct tuple_to_string {
	static void to_string(const T &tup, std::basic_string<char_type_t> &buff) {
		tuple_to_string<char_type_t, T, N - 1>::to_string(tup, buff);
		buff.append(comma());
		buff.append(bg_helper::to_string<char_type_t>(std::get<N - 1>(tup)));
	}
};

template <Character char_type_t, typename T>
struct tuple_to_string<char_type_t, T, 1> {
	static void to_string(const T &tup, std::basic_string<char_type_t> &buff) {
		buff.append(bg_helper::to_string<char_type_t>(std::get<0>(tup)));
	}
};
template <Character char_type_t = bg_helper::char_type, typename... Args>
[[nodiscard]] __attribute__((
	always_inline)) inline std::basic_string<char_type_t>
to_string(const std::tuple<Args...> &value) {
	constexpr size_t size = sizeof...(Args);
	static_assert(size < 10, "too large tuple!!!");
	std::basic_string<char_type_t> buff;
	buff.append(brakets(0));
	tuple_to_string<char_type_t, decltype(value), size>::to_string(value, buff);
	buff.append(brakets(1));
	return buff;
}

template <Character char_type_t = bg_helper::char_type, typename... Args>
[[nodiscard]] __attribute__((
	always_inline)) inline std::basic_string<char_type_t>
concat(const Args &...v) {
	return connect<char_type>(to_string<char_type_t>(v)...);
}

} // namespace bg_helper

#endif //_BGHELPER_TO_STRING_H__
