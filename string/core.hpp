#ifndef _BGHELPER_CORE_H__
#define _BGHELPER_CORE_H__

#include <concepts>
#include <string>
#include <string_view>
#include <type_traits>

namespace bg_helper {

#ifdef UNICODE
using char_type = wchar_t;
#else
using char_type = char;
#endif

// const value
const static std::string CONTAINER_START_SYMBOL = "[";
const static std::string CONTAINER_END_SYMBOL = "]";
const static std::string CONTAINER_SPLIT_SYMBOL = ",";
const static std::wstring CONTAINER_START_SYMBOL_L = L"[";
const static std::wstring CONTAINER_END_SYMBOL_L = L"]";
const static std::wstring CONTAINER_SPLIT_SYMBOL_L = L",";

template <typename T>
concept Character = std::is_same_v<T, char> || std::is_same_v<T, wchar_t>;

template <typename T>
concept Float = std::is_floating_point_v<T>;

template <typename T>
concept Boolean = std::is_same_v<bool, std::decay_t<T>>;

template <typename T>
concept String = std::convertible_to<T, std::string_view> ||
	std::convertible_to<T, std::wstring_view>;

template <typename T>
concept has_to_string = requires(T a) {
	a.to_string();
};

} // namespace bg_helper

#endif //_BGHELPER_CORE_H__
