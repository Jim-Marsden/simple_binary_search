//
// Created by snizzfox on 6/26/21.
//

#include "int_wrapper.hpp"

mylib::test::int_wrapper::int_wrapper(int x)
        :data{x} { }

std::strong_ordering mylib::test::int_wrapper::operator<=>(int x) const { return data<=>x; }

bool mylib::test::int_wrapper::operator==(int_wrapper x) const { return data==x.data; }

mylib::test::int_wrapper::operator int() const {
    return data;
}

mylib::test::int_wrapper& mylib::test::int_wrapper::operator=(int x) {
    data = x;
    return *this;
}
