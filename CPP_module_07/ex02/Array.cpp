
#include "Array.hpp"

template<typename T>
Array<T>::Array() : array(new T[0]), length(0) {}

template<typename T>
Array<T>::Array(unsigned int n) : array(new T[n]()), length(n) {}

template<typename T>
Array<T>::Array(const Array &other) {
	*this = other;
}

template<typename T>
Array<T>	&Array<T>::operator=(const Array &other) {
	if (this != &other) {
		delete[] this->array;
		this->array = new T[other.size()]();
		this->length = other.length;
		for (unsigned int i = 0; i < other.size(); i++)
			this->setElem(other.getElem(i), i);
	}
	return (*this);
}

template<typename T>
Array<T>::~Array() {
	delete[] this->array;
}

template<typename T>
unsigned int Array<T>::size() const {
	return (this->length);
}

template<typename T>
T 	Array<T>::getElem(unsigned int index) const {
	if (index >= this->length)
		throw(Array::OutOfBound());
	return (this->array[index]);
}

template<typename T>
T 	*Array<T>::getArray() const {
	return (this->array);
}

template<typename T>
void 	Array<T>::setElem(T value, unsigned int index) {
	if (index >= this->length)
		throw(Array::OutOfBound());
	this->array[index] = value;
} 

template<typename T>
std::ostream	&operator<<(std::ostream &o, const Array<T> &other ) {
	for (unsigned int i = 0; i < other.size(); i++)
		o << other.getElem(i) << ", ";
	o << std::endl;
	return (o);
}


template<typename T>
const char	*Array<T>::OutOfBound::what() const throw() {
	return ("Out Of Bound !");
}

template class Array<int>;
template class Array<float>;
template class Array<char>;

template std::ostream &operator<<<int>(std::ostream &o, const Array<int> &other);
template std::ostream &operator<<<float>(std::ostream &o, const Array<float> &other);
template std::ostream &operator<<<char>(std::ostream &o, const Array<char> &other);
