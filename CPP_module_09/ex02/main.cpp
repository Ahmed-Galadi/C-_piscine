#include <sys/time.h>
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include "Parsing.hpp"
#include "FordJhonson.hpp"
#include "FordJhonsonBiderect.hpp"

template <typename Container>
void printContainer(Container &c) {
	typename Container::const_iterator it = c.begin();
	while (it != c.end()) {
		std::cout << *it;
		++it;
		if (it != c.end())
			std::cout << ", ";
	}
	std::cout << std::endl;
}

int main(int argc, char *argv[]) {
	struct timeval 	start;
	struct timeval 	end;
	unsigned long 	elapsedInMS;


	if (argc < 2)
		return (0);
		std::cout << "============================================================================================\n";
	try {
		// Vector Test
		Parsing<std::vector<int> > p(argv+1);
		std::vector<int> l = p.inputParse(argc - 1);
		std::cout << "\e[31mUnsorted Numbers:\e[0m\t";
		printContainer<std::vector<int> >(l);
		std::cout << "============================================================================================\n";
		std::cout << "\e[32mSorted Numbers:\e[0m\t\t";
		gettimeofday(&start, NULL);
		std::vector<int> sorted = FordJohnsonAlgo<std::vector<int> >(l);
		gettimeofday(&end, NULL);
		printContainer<std::vector<int> >(sorted);
		elapsedInMS = (end.tv_sec - start.tv_sec) * 1000000L + (end.tv_usec - start.tv_usec);
		std::cout << "\e[94m============================================================================================\e[0m\n";
		std::cout << "\tThe Program Took \e[31m(" << elapsedInMS << " us)\e[0m to Sort \e[32m[" << argc - 1 << "]\e[0m element of \e[33m{std::Vector}\e[0m\n"; 
		std::cout << "\e[94m============================================================================================\e[0m\n";
	
		// List Test
		Parsing<std::list<int> > s(argv+1);
		std::list<int> x = s.inputParse(argc - 1);
		std::cout << "\e[31mUnsorted Numbers:\e[0m\t";
		printContainer<std::list<int> >(x);
		std::cout << "============================================================================================\n";
		std::cout << "\e[32mSorted Numbers:\e[0m\t\t";
		gettimeofday(&start, NULL);
		std::list<int> sorted2 = FordJohnsonAlgoBidirect<std::list<int> >(x);
		gettimeofday(&end, NULL);
		printContainer<std::list<int> >(sorted2);
		elapsedInMS = (end.tv_sec - start.tv_sec) * 1000000L + (end.tv_usec - start.tv_usec);
		std::cout << "\e[94m============================================================================================\e[0m\n";
		std::cout << "\tThe Program Took \e[31m(" << elapsedInMS << " us)\e[0m to Sort \e[32m[" << argc - 1 << "]\e[0m element of \e[33m{std::List}\e[0m\n"; 
		std::cout << "\e[94m============================================================================================\e[0m\n";
	} catch (const std::exception &e) {
		std::cout << "\e[31mError: " << e.what() << "\e[0m" << std::endl;
		return (1);
	}
	return (0);
}