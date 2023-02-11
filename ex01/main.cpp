#include "iter.hpp"

int main(void) {
	int	  array[]  = {1, 2, 3, 4, 5};
	char  array2[] = "Hello";
	float array3[] = {1.1, 2.2, 3.3, 4.4, 5.5};

	iter<int, const int, void (*)(int *, int)>(array, 5, printA);
	iter<char, const int, void (*)(char *, int)>(array2, 5, printA);
	iter<float, const int, void (*)(float *, int)>(array3, 5, printA);

	return (0);
}
