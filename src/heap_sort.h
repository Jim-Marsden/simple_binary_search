//
// Created by snizzfox on 7/2/21.
//

#ifndef SIMPLE_BINARY_SEARCH_HEAP_SORT_H
#define SIMPLE_BINARY_SEARCH_HEAP_SORT_H

namespace my_lib{
    template<class iterator_t>
    void heap_swap(iterator_t begin, iterator_t end) {
        while (begin != end) {
            for (iterator_t iterator{begin}; iterator != end; iterator++) {
                if (*begin < *iterator) { std::swap(*begin, *iterator); }
            }
            std::swap(*begin, *(end - 1 ));
            end--;
        }
    }
} //namespace my_lib

#endif //SIMPLE_BINARY_SEARCH_HEAP_SORT_H
