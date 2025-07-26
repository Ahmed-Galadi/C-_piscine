#pragma once

#include <iostream>
#include <string>
#include <deque>
#include <exception>

template<typename Container>
class	Parsing {
	private:
		std::deque<int>	output;
		char 			**arguments;

		bool	isNegative(int n) const;
		bool 	isValidNumber(char *str) const;
		int		toInt(const std::string &str) const;
		void	haveDups(int size) const;

	public:
		Parsing();
		Parsing(char **args);
		Parsing(const Parsing<Container> &other);
		Parsing &operator=(const Parsing<Container> &other);
		~Parsing();

		Container 				inputParse(int size);
		const std::deque<int> 	&getOutput() const;

		class invalidInput : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class foundDups : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

template<typename Container>
std::ostream &operator<<(std::ostream &o, const Parsing<Container> &parser);

#include "Parsing.tpp"