#include "Parsing.hpp"
#include <sstream>
#include <set>

template<typename Container>
Parsing<Container>::Parsing() {}

template<typename Container>
Parsing<Container>::Parsing(char **args) : arguments(args) {}

template<typename Container>
Parsing<Container>::Parsing(const Parsing<Container> &other) {(void)other;return (this);}

template<typename Container>
Parsing<Container> &Parsing<Container>::operator=(const Parsing<Container> &other) {(void)other;}

template<typename Container>
Parsing<Container>::~Parsing() {}

template<typename Container>
const	std::deque<int>	&Parsing<Container>::getOutput() const {
	return (output);
}
template<typename Container>
void	Parsing<Container>::haveDups(int size) const {
	std::set<int> traversed;
	for (int i = 0; i < size; i++)
		if (!traversed.insert(toInt(std::string(arguments[i]))).second)
			throw (foundDups());
}

template<typename Container>
Container Parsing<Container>::inputParse(int size) {
	try {
		Parsing<Container>::haveDups(size);
	} catch (const std::exception &e) {
		std::cout << "\e[31mError: " << e.what() << "\e[0m" << std::endl;
		exit(1);
	}
	for (int i = 0; i < size; i++)
		if (isValidNumber(arguments[i]))
			output.push_back(toInt(arguments[i]));
	return (Container(output.begin(), output.end()));
}

template<typename Container>
bool	Parsing<Container>::isNegative(int n) const {
	return (0 > n);
}

template<typename Container>
int		Parsing<Container>::toInt(const std::string &str) const {
	std::stringstream	strStream(str);
	int					output;

	strStream >> output;
	if (strStream.fail() || !strStream.eof())
		throw(invalidInput());
	if (isNegative(output))
		throw(invalidInput());
	return (output);
}

template<typename Container>
bool	Parsing<Container>::isValidNumber(char *str) const {
	std::string strHolder(str);
	
	if (strHolder.empty())
		throw(invalidInput());
	toInt(strHolder);
	return (true);
}

template<typename Container>
const char *Parsing<Container>::invalidInput::what() const throw() {
	return ("Invalid Input (no negative values are allowed)!");
}

template<typename Container>
const char *Parsing<Container>::foundDups::what() const throw() {
	return ("Found Duplicates (no duplicated values are allowed)!");
}

template<typename Container>
std::ostream &operator<<(std::ostream &o, const Parsing<Container> &parser) {
	typename std::deque<int>::const_iterator it = parser.getOutput().begin();
	for(; it != parser.getOutput().end(); it++)
		o << *it << ", ";
	return (o);
}


