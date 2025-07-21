#pragma once 

#include <stack>

template<typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack();
		MutantStack(const MutantStack<T> &other);
		MutantStack &operator=(const MutantStack<T> &other);
		~MutantStack();

		typedef typename std::deque<T>::iterator iterator;

		iterator	begin();
		iterator	end();
};

#include "MutantStack.tpp"