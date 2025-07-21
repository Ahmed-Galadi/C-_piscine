#pragma once 

#include <deque>

template<typename T>
class MutantStack {
	private:
		std::deque<T> 	*data;
	
	public:
		MutantStack();
		MutantStack(const MutantStack<T> &other);
		MutantStack &operator=(const MutantStack<T> &other);
		~MutantStack();

		T		top() const;
		size_t 	size() const;
		bool 	empty() const;
		T		pop();
		void	push(T value);
		void	swap(MutantStack<T> &otherStack);

		class isEmpty : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

#include "MutantStack.tpp"