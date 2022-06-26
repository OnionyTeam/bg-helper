#ifndef _BGHELPER_TO_STRING_H__
#define _BGHELPER_TO_STRING_H__

#include "core.hpp"
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

template <
	Character char_type_t = bg_helper::char_type, std::integral T,
	typename = std::enable_if_t<!Boolean<T>, std::basic_string<char_type>>>
[[nodiscard]] __attribute__((
	always_inline)) inline std::basic_string<char_type_t>
to_string(const T value) noexcept {
	if constexpr (std::is_same_v<wchar_t, char_type_t>) {
		return std::to_wstring(value);
	} else {
		return std::to_string(value);
	}
}

template <Character char_type_t = bg_helper::char_type, Float T>
[[nodiscard]] __attribute__((
	always_inline)) inline std::basic_string<char_type_t>
to_string(const T value) noexcept {
	if constexpr (std::is_same_v<wchar_t, char_type_t>) {
		return std::to_wstring(value);
	} else {
		return std::to_string(value);
	}
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

	auto func = [&](const string_view START_SYMBOL,
					const string_view END_SYMBOL,
					const string_view SPLIT_CHAR) {
		std::basic_string<char_type_t> buffer;
		auto size = value.size();
		if (size > 10) {
			buffer.reserve(size * 2);
		}
		buffer.append(START_SYMBOL);
		for (auto &&e : value) {
			if constexpr (String<typename T::value_type>) {
				if constexpr (std::is_same_v<wchar_t, char_type_t>) {
					buffer.append(connect<char_type_t>(
						L"\"", to_string<char_type_t>(e), L"\""));
				} else {
					buffer.append(connect<char_type_t>(
						"\"", to_string<char_type_t>(e), "\""));
				}
			} else {
				buffer.append(to_string<char_type_t>(e));
			}
			buffer.append(SPLIT_CHAR);
		}
		buffer.erase(buffer.size() - SPLIT_CHAR.size());
		buffer.append(END_SYMBOL);
		return buffer;
	};
	if constexpr (std::is_same_v<wchar_t, char_type_t>) {
		return func(bg_helper::CONTAINER_START_SYMBOL_L,
					bg_helper::CONTAINER_END_SYMBOL_L,
					bg_helper::CONTAINER_SPLIT_SYMBOL_L);
	} else {
		return func(bg_helper::CONTAINER_START_SYMBOL,
					bg_helper::CONTAINER_END_SYMBOL,
					bg_helper::CONTAINER_SPLIT_SYMBOL);
	}
}

template <Character char_type_t = bg_helper::char_type, typename... Args>
[[nodiscard]] __attribute__((
	always_inline)) inline std::basic_string<char_type_t>
concat(const Args &...v) {
	return connect<char_type>(to_string<char_type_t>(v)...);
}

} // namespace bg_helper

#endif //_BGHELPER_TO_STRING_H__
