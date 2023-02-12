#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;

template <class T>
class Array {

  private:
	unsigned int _n;
	T			*_array;

  public:
	unsigned int getN() const {
		return this->_n;
	};

	T getArray(int i) const {
		return this->_array[i];
	};

	void setArray(int i, T newArr) {
		this->checkException(i);
		this->_array[i] = newArr;
	}

	Array() {
		cout << "Array default constructor" << endl;
		this->_n	 = -1;
		this->_array = new T();
	};

	Array(unsigned int n) {
		cout << "Array constructor" << endl;
		if (n <= 0) {
			throw Array::OutOfRangeException();
		}
		this->_n	 = n;
		this->_array = new T[n]();
	};

	Array(const Array &array) {
		cout << "Array copy constructor" << endl;
		this->_array = new T;
		*this		 = array;
	};

	Array<T> &operator=(const Array &array) {
		cout << "Array copy assignment operator" << endl;
		if (this != &array) {
			delete[] this->_array;
			this->_n = array.getN();
			if (this->_n > 0) {
				this->_array = new T[this->_n];
				for (unsigned int i = 0; i < this->_n; i++) {
					this->setArray(i, array.getArray(i));
				}
			} else {
				this->_array = new T();
			}
		}
		return *this;
	};

	~Array() {
		cout << "Array destructor" << endl;
		delete[] this->_array;
	};

	void checkException(int i) {
		if (i < 0 || static_cast<int>(this->_n) <= i) {
			throw Array::OutOfRangeException();
		}
	}

	T operator[](int i) const {
		this->checkException(i);
		return this->_array[i];
	};

	T &operator[](int i) {
		this->checkException(i);
		return this->_array[i];
	};

	class OutOfRangeException : public std::exception {
	  public:
		virtual const char *what() const throw() {
			return "Out of range";
		}
	};
};

#endif
