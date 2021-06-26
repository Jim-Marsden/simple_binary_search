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

//    struct meow{
//        int data;
//        meow() = default;
//        meow( int x) : data{x} {}
//        meow( meow const &) = default;
//        meow( meow &&) = default;
//        ~meow() = default;
//        meow & operator=(meow const & me) = default;
//        std::strong_ordering operator<=>(int x ){return data <=> x;};
//        auto operator <=>(meow const&) const = default;
//
//        bool operator ==(meow x){return data == x.data;}
//        explicit operator int(){
//            return data;
//        }
//        int & operator=(int x){ return data = x;}
//    };
//
//
//   [[depricated]] int main2() {
//        std::vector my_vec{0,1,2,3,4,5,6,7,8,9,10};
//
//        std::vector<meow> strange{0,1,2,3,4,5,6,7,8,9,0,11};
//        meow puurrrr{3};
//
//        std::cout << "meows " <<  static_cast<int>(*my_find(strange.begin(), strange.end(), puurrrr)) << '\n';
//
//        std::cout << "ints " << *my_find(my_vec.begin(), my_vec.end(), 3) << '\n';
//
//        std::cout << "ints - meow " << *my_find(my_vec.begin(), my_vec.end(), static_cast<int>(puurrrr)) << '\n';
//
//        std::string test_string = "abcdefghijklmnop";
//
//        std::cout << "string: " << *my_find(test_string.begin(), test_string.end(), 'c') << '\n';
//    }


} // mylib

#endif //SIMPLE_BINARY_SEARCH_BINARY_SEARCH_HPP
