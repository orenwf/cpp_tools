#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <random>
#include <iostream>
#include <type_traits>
#include <string>

namespace tools {

    // Random Vector Generator for Arithmetic types
    template <
        typename N = int, typename = std::enable_if_t<std::is_arithmetic<N>::value>
        >
    std::vector<N> rand_set(unsigned int size, N min, N max);

    // Container Printer using std::vector
    template <
        typename N = int, typename = std::enable_if_t<std::is_arithmetic<N>::value>
        >
    std::ostream& operator<<(std::ostream& os, const std::vector<N>& my_vector);

    // Sorted Array Test
    template <
        typename N = int, typename = std::enable_if_t<std::is_arithmetic<N>::value>
        >
    bool is_sorted(const std::vector<N>& my_vector);

}   // namespace tools
#endif
