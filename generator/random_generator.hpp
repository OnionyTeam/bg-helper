#ifndef _BGHELPER_RANDOM_GENERATOR_H__
#define _BGHELPER_RANDOM_GENERATOR_H__

#include <type_traits>
#include "../string/core.hpp"

namespace bg_helper {
   namespace generator {
       
       template <typename T>
       T random(const T &min, const T &max)
           requires std::is_integral_v<T>;

       template <typename T>
       T random(const T &min, const T &max)
           requires String<T>;

   } // generater
} // bg_helper

#endif // _BGHELPER_RANDOM_GENERATOR_H__

