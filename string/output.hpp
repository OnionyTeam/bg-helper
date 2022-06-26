#ifndef _BGHELPER_OUTPUT_H__
#define _BGHELPER_OUTPUT_H__

#include "string_concat.hpp"
#include "to_string.hpp"
#include <algorithm>
#include <cstdio>
#include <exception>
#include <list>
#include <ostream>
#include <string>
#include <utility>

namespace bg_helper {

class Format {
  public:
	const static size_t DEFUALT_SIZE = 100;
	using char_type_t = char;

  private:
	/* std::list<std::basic_string<char_type>> source; */
	std::basic_string<char_type_t> buffer;

  public:
	Format() { buffer.reserve(DEFUALT_SIZE); }
	template <typename... Args> Format(const Args &...args) {
		buffer.reserve(DEFUALT_SIZE);
		buffer.append(bg_helper::concat(args...));
	}
	/* template <typename T> */
	/* Format &operator,(const std::basic_string_view<char_type_t> &t) { */
	/* 	buffer.append(std::move(t)); */
	/* 	return *this; */
	/* }; */
	template <typename T> Format &operator,(const T &t) {
		buffer.append(bg_helper::to_string<char_type_t>(t));
		return *this;
	};

	std::basic_string<char_type_t> to_string() { return buffer; }

	friend std::ostream &operator<<(std::ostream &os, Format &f) {
		os << f.to_string();
		return os;
	}
};

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
