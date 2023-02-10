#include "iter.hpp" 

int	main(void) {
	int		array[] = {1, 2, 3, 4, 5};
	char	array2[] = "Hello";
	float	array3[] = {1.1, 2.2, 3.3, 4.4, 5.5};

	iter<int, int, void (*)(const int *, int)>(array, 5, printA);
	iter<char, int, void (*)(const char *, int)>(array2, 5, printA);
	iter<float, int, void (*)(const float *, int)>(array3, 5, printA);

	return (0);
}
