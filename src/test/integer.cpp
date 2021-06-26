//
// Created by Jim Marsden on 6/26/21.
//


#include "../../binary_search.hpp"

#include <catch2/catch.hpp>
#include <vector>


TEST_CASE("binary search - int"){
    constexpr auto vector_size{0xffff};
    std::vector<int> int_vec{};
    int_vec.reserve(vector_size);
    for(auto i{0}; i < vector_size; ++i ) int_vec.emplace_back(i);
    for(auto const & e : int_vec){
        REQUIRE(*mylib::find(int_vec.begin(), int_vec.end(), e) == e);
    }
    REQUIRE(mylib::find(int_vec.begin(), int_vec.end(), -vector_size) == int_vec.end());
    REQUIRE(mylib::find(int_vec.begin(), int_vec.end(), vector_size + 2) == int_vec.end());
}