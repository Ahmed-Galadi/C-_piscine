#include "Span.hpp"
#include <iostream>

int main()
{
Span sp = Span(5);
try {
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    sp.addNumber(42);
} catch (Span::sizeExceeded &e) {
    std::cout << e.what() << std::endl;
}

try {
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
} catch (Span::invalidOperation &e) {
    std::cout << e.what() << std::endl;
}

Span sp1 = Span();
try {
    std::cout << sp1.shortestSpan() << std::endl;
} catch (Span::invalidOperation &e) {
    std::cout << e.what() << std::endl;
}

std::vector<int> v;
std::cout << "vector => ";
for (size_t i = 0 ; i < 100; i+=2)
    v.push_back(i);
for (size_t i = 0; i < v.size(); i++)
    std::cout << v[i] << ", ";
std::cout << "\n";

Span sp2 = Span(v.size());
std::cout << "span => ";
sp2.addRange(v.begin(), v.end());
for (unsigned int i = 0; i < sp2.size(); i++)
    std::cout << sp2.getElement(i) << ", ";
std::cout << "\n";

Span sp3 = Span(10);
try {
    sp3.addRange(v.begin(), v.end());
} catch (Span::sizeExceeded &e) {
    std::cout << "Error: " << e.what() << std::endl;
}
return 0;
}