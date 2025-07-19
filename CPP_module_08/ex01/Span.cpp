#include "Span.hpp"
#include <algorithm>
#include <vector>
#include <numeric>

Span::Span() : data(NULL), N(0) {}

Span::Span(unsigned int N) : data(new std::vector<int>()), N(N) {}

Span::Span(const Span &other) {
	*this = other;
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

int Span::shortestSpan() const {
	std::vector<int> holder(*data);
	std::vector<int> output(N);

	std::sort(holder.begin(), holder.end());
	std::adjacent_difference(holder.begin(), holder.end(), output.begin());
	std::sort(output.begin() + 1, output.end());
	return (output[1]);
}

int Span::longestSpan() const {
	int smallest = std::min_element(data->begin(), data->end())[0];
	int biggest = std::max_element(data->begin(), data->end())[0];

	return (biggest - smallest);
}

const char *Span::sizeExceeded::what() const throw() {
	return ("ERROR: Size Exeeded!");
}
