#ifndef _BGHELPER_OUTPUT_H__
#define _BGHELPER_OUTPUT_H__

#include "string_concat.hpp"
#include <cstdio>

namespace bg_helper {

template <Character char_type_t = bg_helper::char_type, typename... Args>
void print(const Args &...v) {
	const auto buffer = concat<char_type_t>(v...);
	if constexpr (std::is_same_v<char_type_t, char>) {
		printf("%s", buffer.c_str());
	} else {
		wprintf(L"%ls", buffer.c_str());
	}
}

template <Character char_type_t = bg_helper::char_type, typename... Args>
void println(const Args &...v) {
	if constexpr (std::is_same_v<char_type_t, char>) {
		const auto buffer = concat<char_type_t>(v...);
		printf("%s\n", buffer.c_str());
	} else {
		const auto buffer = concat<char_type_t>(v...);
		wprintf(L"%ls\n", buffer.c_str());
	}
}

} // namespace bg_helper

#endif // _BGHELPER_OUTPUT_H__
