// #include "Array.hpp"

// int main() {
// 	int		   n = 5;
// 	Array<int> a(n);
// 	Array<int> b(a);
// 	Array<int> c;
// 	c = a;
// 	for (int i = 0; i < n; i++) {
// 		a.setArray(i, i);
// 	}
// 	for (int i = 0; i < n; i++) {
// 		cout << a.getArray(i) << endl;
// 	}
// 	for (int i = 0; i < n; i++) {
// 		cout << b.getArray(i) << endl;
// 	}
// 	for (int i = 0; i < n; i++) {
// 		cout << c.getArray(i) << endl;
// 	}
// 	return 0;
// }

#include "Array.hpp"
#include <iostream>

#define MAX_VAL 750
int main(int, char **) {
	Array<int> numbers(MAX_VAL);
	int		  *mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++) {
		const int value = rand();
		numbers[i]		= value;
		mirror[i]		= value;
	}
	// SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++) {
		if (mirror[i] != numbers[i]) {
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try {
		numbers[-2] = 0;
	} catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
	}
	try {
		numbers[MAX_VAL] = 0;
	} catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++) {
		numbers[i] = rand();
	}
	delete[] mirror; //
	return 0;
}