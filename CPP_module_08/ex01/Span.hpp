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

		void	addNumber(int num);
		int 	shortestSpan() const;
		int 	longestSpan() const;

		class sizeExceeded : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};