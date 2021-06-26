//
// Created by snizzfox on 6/26/21.
//

#ifndef SIMPLE_BINARY_SEARCH_INT_WRAPPER_HPP
#define SIMPLE_BINARY_SEARCH_INT_WRAPPER_HPP
#include <compare>
class int_wrapper {
    int data;
public:
    int_wrapper() = default;

    int_wrapper(int x); // intentional implicit constructor
    int_wrapper(int_wrapper const&) = default;

    int_wrapper(int_wrapper&&) = default;

    ~int_wrapper() = default;

    int_wrapper& operator=(int_wrapper const& me) = default;

    std::strong_ordering operator<=>(int x) const;;

    auto operator<=>(int_wrapper const&) const = default;

    bool operator==(int_wrapper x) const;

    explicit operator int() const;

    int_wrapper& operator=(int x);
};

#endif //SIMPLE_BINARY_SEARCH_INT_WRAPPER_HPP
