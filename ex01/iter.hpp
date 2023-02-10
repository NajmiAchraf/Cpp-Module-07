#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <class A, class B>
void	printA(const A *array, B i) {
	std::cout << array[i] << std::endl;
}

template <class A, class B, class C>
void	iter(const A *array, const B &length, C func) {
	for (B i = 0; i < length; i++) {
		func(array, i);
	}
}

#endif
