
#ifndef _BGHELPER_STRING_CONCAT_H__
#define _BGHELPER_STRING_CONCAT_H__

#include "core.hpp"
#include <cassert>
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
template <Character char_type_t = bg_helper::char_type, typename... Args>
[[nodiscard]] std::basic_string<char_type_t> connect(const Args &...args) {
	size_t len = 0;
	for (auto s : {args...})
		len += std::basic_string_view<char_type_t>(s).size();

	std::string result;
	result.reserve(len); // <--- preallocate result
	for (auto s : {args...})
		result += s;
	return result;
}

template <Character char_type_t = bg_helper::char_type,
		  std::ranges::range Container>
requires String<typename Container::value_type>
[[nodiscard]] std::basic_string<char_type_t>
connect(const Container &container) {
	size_t size = 0;
	for (auto &&e : container) {
		size += e.size();
	}

	std::basic_string<char_type_t> buffer;
	buffer.reserve(size);

	for (auto &&e : container) {
		buffer += e;
	}
	return buffer;
}

/**
 * Summary: connect elements to string
 * Paramters:
 *     v: elements to concatenate
 * Example:
 *     concat("PI = ", 3.1415) --> "PI = 3.1415"
 */

} // namespace bg_helper

#endif //_BGHELPER_STRING_CONCAT_H__
