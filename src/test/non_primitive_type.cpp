//
// Created by Jim Marsden on 6/26/21.
//

#include "../../binary_search.hpp"

#include <catch2/catch.hpp>
#include <vector>
#include "int_wrapper.hpp"



TEST_CASE("binary search - int_wrapper"){
    using namespace mylib::test;
    constexpr auto vector_size{0xffff};
    std::vector<int_wrapper> wrapper{};
    wrapper.reserve(vector_size);
    for(auto i{0}; i < vector_size; ++i ) wrapper.emplace_back(i);
    REQUIRE(mylib::find(wrapper.begin(), wrapper.end(), int_wrapper{0}) != wrapper.end());
    REQUIRE(mylib::find(wrapper.begin(), wrapper.end(), int_wrapper{-1}) == wrapper.end());
    REQUIRE(mylib::find(wrapper.begin(), wrapper.end(), int_wrapper{vector_size + 2}) == wrapper.end());

    for(auto const & e : wrapper){
        REQUIRE(*mylib::find(wrapper.begin(), wrapper.end(), e) == e);
    }
}