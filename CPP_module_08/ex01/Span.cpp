#include "Span.hpp"
#include <algorithm>
#include <vector>
#include <numeric>

Span::Span() : data(NULL), N(0) {}

Span::Span(unsigned int N) : data(new std::vector<int>()), N(N) {}

Span::Span(const Span &other) {
	if (this != &other) {
		data = new std::vector<int>(*other.data);
		N = other.N;
	}
}

Span &Span::operator=(const Span &other) {
	if (this != &other) {
		delete data;
		data = new std::vector<int>(*other.data);
		N = other.N;
	}
	return (*this);
}

Span::~Span() {
	delete data;
}

void 	Span::addNumber(int num) {
	if (data->size() >= N)
		throw (Span::sizeExceeded());
	this->data->push_back(num);
}

void	Span::addRange(iterator begin, iterator end) {
	size_t range_size = std::distance(begin, end);
    
    if (data->size() + range_size > N)
        throw (Span::sizeExceeded());
    
    data->insert(data->end(), begin, end);
}

int		Span::getElement(unsigned int index) const {
	if (index >= N)
		throw (Span::sizeExceeded());
	return ((*data)[index]);
}

unsigned int Span::size() const {
	return (N);
}

int Span::shortestSpan() const {
	if (N == 0)
		throw (Span::invalidOperation());
	std::vector<int> holder(*data);
	std::vector<int> output(N);

	std::sort(holder.begin(), holder.end());
	std::adjacent_difference(holder.begin(), holder.end(), output.begin());
	std::sort(output.begin() + 1, output.end());
	return (output[1]);
}

int Span::longestSpan() const {
	if (N == 0)
		throw (Span::invalidOperation());
	int smallest = std::min_element(data->begin(), data->end())[0];
	int biggest = std::max_element(data->begin(), data->end())[0];

	return (biggest - smallest);
}

const char *Span::sizeExceeded::what() const throw() {
	return ("ERROR: Size Exeeded!");
}

const char *Span::invalidOperation::what() const throw() {
	return ("ERROR: Invalid Operation!");
}