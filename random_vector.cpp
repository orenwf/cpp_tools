#include "tools.hpp"

// Random Vector Generator for Arithmetic types
template <
    typename N = int, typename = std::enable_if_t<std::is_arithmetic<N>::value>
    >
std::vector<N> rand_set(unsigned int size, N min, N max)
{
    std::random_device rd;          // initialize seed engine
    std::mt19937_64 rng(rd());      // apply random number generator with seed (Mersenne-Twister 64 bit)
    std::uniform_int_distribution<N> uni(min,max);    // de-biasing
    std::vector<N> my_vector;
    for(int i=0; i<size; ++i)
        my_vector.push_back(uni(rng)); // fill the vector
    return my_vector;
} // Random Vector Generator

// Container Printer using std::vector
template <
    typename N = int, typename = std::enable_if_t<std::is_arithmetic<N>::value>
    >
std::ostream& operator<<(std::ostream& os, const std::vector<N>& my_vector)
{
    auto itr = my_vector.cbegin();
    os << "{" << *itr;
    while( ++itr!=my_vector.cend() )
        os << ", " << *itr;
    return os << "}";
} // Container Printer

// Sorted Array Test
template <
    typename N = int, typename = std::enable_if_t<std::is_arithmetic<N>::value>
    >
bool is_sorted(const std::vector<N>& my_vector)
{
    auto itr = my_vector.cbegin();
    while( ++itr!=my_vector.cend() )
    {
        if(*itr.next()<*itr)
            return false;
    }
    return true;
}   // Sorted Array Test

