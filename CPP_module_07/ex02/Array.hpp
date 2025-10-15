#pragma once

#include <iostream>
#include <exception>

template<typename T>
class Array {
	private:
		T 				*array;
		unsigned int 	length;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		Array &operator=(const Array &other);
		T &operator[](unsigned int index);
		T operator[](unsigned int index) const;
		~Array();

		unsigned int 	size() const;
		T				getElem(unsigned int index) const;
		T				*getArray() const;
		void			setElem(T value, unsigned int index);

		class	OutOfBound : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

template<typename T>
std::ostream	&operator<<(std::ostream &o, const Array<T> &other);
