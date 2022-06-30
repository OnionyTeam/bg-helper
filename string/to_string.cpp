#include "to_string.hpp"

namespace bg_helper {

template <Character char_type_t, typename T>
struct tuple_to_string<char_type_t, T, 1>::to_string(
	const T &tup, std::basic_string<char_type_t> &buff) {} // bg_helper
