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
#if defined(__linux__) || defined(__APPLE__)
#include <unistd.h>
#endif
#if defined(_WIN32)
#include <windows.h>
#endif

namespace bg_helper {

template <Character char_type_t = bg_helper::char_type> class Format {
  public:
	const static size_t DEFUALT_SIZE = 512;

  private:
	std::basic_string<char_type_t> buffer;

  public:
	Format() { buffer.reserve(DEFUALT_SIZE); }
	template <typename... Args> Format(const Args &...args) {
		buffer.reserve(DEFUALT_SIZE);
		buffer.append(std::move(bg_helper::concat(args...)));
	}

	template <typename T> Format &operator|(const T &t) {
		buffer.append(bg_helper::to_string<char_type_t>(t));
		return *this;
	};

	void clear() { buffer.clear(); }
	const std::basic_string<char_type_t> &to_string() const { return buffer; }
	std::basic_string<char_type_t> to_string() { return buffer; }

	friend std::ostream &operator<<(std::ostream &os, const Format &f) {
		os << f.to_string();
		return os;
	}
};

template <Character char_type_t = bg_helper::char_type, typename... Args>
constexpr void print(const Args &...v) {
#if defined(__linux__) || defined(__APPLE__)
	if constexpr (std::is_same_v<char_type_t, char>) {
		const auto buffer = concat<char_type_t>(v...);
		write(STDOUT_FILENO, buffer.c_str(), buffer.size());
	} else {
		const auto buffer = concat<char_type_t>(v...);
		write(STDOUT_FILENO, buffer.c_str(),
			  buffer.size() * sizeof(char_type_t));
	}
#elif defined(_WIN32)
	if constexpr (std::is_same_v<char_type_t, char>) {
		const auto buffer = concat<char_type_t>(v...);
		WriteConsoleA(GetStdHandle(handle), buffer.c_str(),
					  static_cast<unsigned long>(buffer.size()), nullptr,
					  nullptr);
	} else {
		const auto buffer = concat<char_type_t>(v...);
		write(STDOUT_FILENO, buffer.c_str(),
			  buffer.size() * sizeof(char_type_t));
		WriteConsoleW(GetStdHandle(handle), buffer.c_str(),
					  static_cast<unsigned long>(buffer.size()), nullptr,
					  nullptr);
	}
#endif
}

template <Character char_type_t = bg_helper::char_type, typename... Args>
constexpr void println(const Args &...v) {
#if defined(__linux__) || defined(__APPLE__)
	if constexpr (std::is_same_v<char_type_t, char>) {
		const auto buffer = concat<char_type_t>(v..., "\n");
		write(STDOUT_FILENO, buffer.c_str(), buffer.size());
	} else {
		const auto buffer = concat<char_type_t>(v..., L"\n");
		write(STDOUT_FILENO, buffer.c_str(),
			  buffer.size() * sizeof(char_type_t));
	}
#elif defined(_WIN32)
	if constexpr (std::is_same_v<char_type_t, char>) {
		const auto buffer = concat<char_type_t>(v..., "\n");
		WriteConsoleA(GetStdHandle(handle), buffer.c_str(),
					  static_cast<unsigned long>(buffer.size()), nullptr,
					  nullptr);
	} else {
		const auto buffer = concat<char_type_t>(v..., L"\n");
		write(STDOUT_FILENO, buffer.c_str(),
			  buffer.size() * sizeof(char_type_t));
		WriteConsoleW(GetStdHandle(handle), buffer.c_str(),
					  static_cast<unsigned long>(buffer.size()), nullptr,
					  nullptr);
	}
#endif
}

} // namespace bg_helper

#endif // _BGHELPER_OUTPUT_H__
