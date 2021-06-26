//
// Created by snizzfox on 6/26/21.
//

#ifndef SIMPLE_BINARY_SEARCH_BINARY_SEARCH_HPP
#define SIMPLE_BINARY_SEARCH_BINARY_SEARCH_HPP
#include <iterator>
#include <concepts>
#include <algorithm>
#include <compare>
namespace mylib{

    template<typename T, typename U>
    concept RA_Iterator = requires(T a, U to_find){
        {*a} -> std::convertible_to<U>;
        {a + 5} -> std::convertible_to<T>;
        {a - 5} -> std::convertible_to<T>;
        {a = a} -> std::convertible_to<T>;
        {a == a} -> std::same_as<bool>;
        {a != a} -> std::same_as<bool>;
        {std::distance(a,a)};
        {*a} -> std::convertible_to<std::iter_value_t<T>>;
    };

    template<class findable_t>
    concept Findable = requires (findable_t find){
        {find < find} -> std::same_as<bool>;
        {find > find} -> std::same_as<bool>;
        {find == find} -> std::same_as<bool>;
    };

    template<Findable find_t, RA_Iterator<find_t> iterator_t>
    iterator_t find(iterator_t const &begin, iterator_t const &end, find_t find) {
        iterator_t temp_iter{begin}, local_begin{begin}, local_end{end};
        unsigned long size{};
        while (local_begin != local_end) {
            size = std::distance(local_begin, local_end);

            if (temp_iter = local_begin + (size / 2); *temp_iter == find) {
                return temp_iter;
            } else if (*temp_iter < find) {
                local_begin = temp_iter;
            } else if (*temp_iter > find) {
                local_end = temp_iter;
            }
        }
        return end;
    }

} // mylib

#endif //SIMPLE_BINARY_SEARCH_BINARY_SEARCH_HPP
