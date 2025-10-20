#pragma once

#include <vector>
#include <exception>

class Span {
	private:
		std::vector<int>	*data;
		unsigned int 		N;
	
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		typedef typename std::vector<int>::iterator iterator;

		void	addNumber(int num);
		void	addRange(iterator begin, iterator end);
		int 	shortestSpan() const;
		int 	longestSpan() const;
		int		getElement(unsigned int index) const;
		unsigned int size() const;

		class sizeExceeded : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class invalidOperation : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};