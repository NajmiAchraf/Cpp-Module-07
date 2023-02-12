#include "Array.hpp"

int main() {
	int		   n = 5;
	Array<int> a(n);
	Array<int> b(a);
	Array<int> c;
	c = a;
	for (int i = 0; i < n; i++) {
		a.setArray(i, i);
	}
	for (int i = 0; i < n; i++) {
		cout << a.getArray(i) << endl;
	}
	for (int i = 0; i < n; i++) {
		cout << b.getArray(i) << endl;
	}
	for (int i = 0; i < n; i++) {
		cout << c.getArray(i) << endl;
	}
	return 0;
}
