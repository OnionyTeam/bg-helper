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
	using char_type_t = char;

  private:
	std::list<std::basic_string<char_type>> source;
	std::basic_string<char_type_t> buffer;
	bool has_changed;

  public:
	Format() : source(), buffer() {}
	template <typename... Args> Format(const Args &...args) : buffer() {
		source.emplace_back(bg_helper::concat(args...));
		has_changed = true;
	}
	template <typename T> Format &operator,(T &t) {
		source.emplace_back(bg_helper::to_string<char_type_t>(t));
		has_changed = true;
		return *this;
	};
	template <typename T> Format &operator,(T &&t) {
		source.emplace_back(bg_helper::to_string<char_type_t>(std::move(t)));
		has_changed = true;
		return *this;
	};

	std::basic_string<char_type_t> to_string() {
		if (has_changed)
			buffer = connect<char_type_t>(source);
		return buffer;
	}

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
