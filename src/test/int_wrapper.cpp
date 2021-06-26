//
// Created by snizzfox on 6/26/21.
//

#include "int_wrapper.hpp"

int_wrapper::int_wrapper(int x)
        :data{x} { }

std::strong_ordering int_wrapper::operator<=>(int x) const { return data<=>x; }

bool int_wrapper::operator==(int_wrapper x) const { return data==x.data; }

int_wrapper::operator int() const {
    return data;
}

int_wrapper& int_wrapper::operator=(int x) {
    data = x;
    return *this;
}
