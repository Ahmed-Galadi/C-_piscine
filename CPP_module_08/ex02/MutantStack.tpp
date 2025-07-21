#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack() {
	data = new std::deque<T>();
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack &other) {
	 data = new std::deque<T>(*(other.data));
}

template<typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &other) {
	if (this != &other) {
		delete data;
		data = new std::deque<T>(*(other.data));
	}
	return *this;
}

template<typename T>
MutantStack<T>::~MutantStack() {
	delete data;
}

template<typename T>
T 	MutantStack<T>::top() const {
	if (!data->empty())
		return (data->front());
	throw(isEmpty());
}

template<typename T>
size_t		MutantStack<T>::size() const {
	return (data->size());
}

template<typename T>
bool	MutantStack<T>::empty() const {
	return (data->empty());
}

template<typename T>
T	MutantStack<T>::pop() {
	if (data->empty())
		throw(isEmpty());

	T output = data->front();
	data->pop_front();
	return (output);
}

template<typename T>
void	MutantStack<T>::push(T value) {
	data->push_front(value);
}

template<typename T>
void	MutantStack<T>::swap(MutantStack<T> &otherStack) {
	data->swap(*(otherStack.data));
}

template<typename T>

const char *MutantStack<T>::isEmpty::what() const throw() {
	return ("Error: Stack is Empty!");
}
