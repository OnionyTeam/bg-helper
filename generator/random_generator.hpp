#ifndef _BGHELPER_RANDOM_GENERATOR_H__
#define _BGHELPER_RANDOM_GENERATOR_H__

#include "../string/core.hpp"
#include <random>
#include <type_traits>

namespace bg_helper {
namespace generator {

class Random {
  private:
	std::mt19937 _rng;

  public:
	Random(std::random_device device = std::random_device()) : _rng(device()) {}

	template <typename T>
	T randdigit(const T &min, const T &max) requires std::is_integral_v<T> {
		std::uniform_int_distribution<T> dist(min, max);
		return dist(_rng);
	}
};

static Random random;

} // namespace generator
} // namespace bg_helper

#endif // _BGHELPER_RANDOM_GENERATOR_H__
