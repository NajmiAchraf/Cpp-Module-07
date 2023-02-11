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
	T			*_arr;

  public:
	unsigned int getN() {
		return this->_n;
	};

	T getArr() {
		return this->_arr;
	};

	Array() {
		cout << "Array default constructor" << endl;
		this->_n   = -1;
		this->_arr = new T();
	};

	Array(unsigned int n) {
		cout << "Array constructor" << endl;
		this->_n   = n;
		this->_arr = new T[n]();
	};

	Array(const Array &array) {
		cout << "Array copy constructor" << endl;
		this->_arr = new T;
		*this	   = array;
	};

	Array &operator=(const Array &array) {
		cout << "Array copy assignment operator" << endl;
		if (*this != *array) {
			delete[] this->_arr;
			this->_n = array.getN();
			if (this->_n != -1) {
				this->getArr = new T[this->_n];
				*this->_arr	 = *array.getArr();
			} else {
				this->getArr = new T();
				*this->_arr	 = *array.getArr();
			}
		}
		return *this;
	};

	~Array() {
		cout << "Array destructor" << endl;
		delete[] this->_arr;
	};

	T &operator[](unsigned int i) {
		if (i >= this->_n) {
			throw std::out_of_range("Out of range");
		}
		return this->_arr[i];
	};

	class OutOfRangeException : public std::exception {
	  public:
		virtual const char *what() const throw() {
			return "Out of range";
		}
	};
};

#endif
