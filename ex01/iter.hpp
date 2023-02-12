#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <class A, class B, class C>
void iter(A *array, B &length, C func) {
	for (unsigned int i = 0; static_cast<B>(i) < length; i++) {
		func(array, i);
	}
}

#endif
