#include "random_generator.hpp"
#include <array>
#include <algorithm>
#include <random>

namespace bg_helper {
   namespace generater {
       
       //constexpr std::array<char> default_array {
           //"0123456789"
           //"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
           //"abcdefghijklmnopqrstuvwxyz"
       //};
       //constexpr std::array<wchar_t> default_warray {
           //L"0123456789"
           //L"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
           //L"abcdefghijklmnopqrstuvwxyz"
       //}
       template <typename T>
       T random(const T &min, const T &max)
           requires std::is_integral_v<T> {
           auto device = std::random_device();
           std::mt19937 rng(device());
           std::uniform_int_distribution<T> dist(min, max);
           return dist(rng);
       }

       template <typename T>
       T random(const T &min, const T &max)
           requires std::is_floating_point_v<T> {
           auto device = std::random_device();
           std::mt19937 rng(device());
           std::uniform_real_distribution<T> dist(min, max);
           return dist(rng);
       } 

       //template <Character char_type = bg_helper::char_type>
       //std::basic_string<char_type> random(const size_t &min, const size_t &max, const std::array<char_type> &char_table)
           //requires String<T>
       //{
           //size_t size = char_table.size();
           //std::basic_string<char_type> buffer;
           //size_t string_size = random(min, max);
           //buffer.reserve(string_size);
           //std::generate_n(buffer, [&](){
               //return char_table[random(0, string_size - 1)];        
           //});
       //}


   } // generater
} // bg_helper

