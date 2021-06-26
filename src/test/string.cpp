//
// Created by Jim Marsden on 6/26/21.
//

#include "../../binary_search.hpp"

#include <catch2/catch.hpp>
#include <string>


TEST_CASE("binary search - const string"){
    using namespace std::string_literals;
    auto const one_number{"a"s};
    auto const string{"abcdefghijklmnop"s};
    REQUIRE(mylib::find(one_number.begin(), one_number.end(), 'a') != one_number.end());
    REQUIRE(mylib::find(one_number.begin(), one_number.end(), 'b') == one_number.end());
    REQUIRE(mylib::find(string.begin(), string.end(), 'a') != string.end());

    for(auto const & e : string){
        REQUIRE(*mylib::find(string.begin(), string.end(), e) == e);
    }
}

TEST_CASE("binary search - non const string"){
    using namespace std::string_literals;
    auto one_number{"a"s};
    auto string{"abcdefghijklmnop"s};
    REQUIRE(mylib::find(one_number.begin(), one_number.end(), 'a') != one_number.end());
    REQUIRE(mylib::find(one_number.begin(), one_number.end(), 'b') == one_number.end());
    REQUIRE(mylib::find(string.begin(), string.end(), 'a') != string.end());
}

TEST_CASE("binary search - empty string"){
    std::string string{};
    REQUIRE(mylib::find(string.begin(), string.end(), 'a') == string.end());
}