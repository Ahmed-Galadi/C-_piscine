#include <sys/time.h>
#include <iostream>
#include <vector>
#include <set>
#include "Parsing.hpp"

int binaryInsertionIndex(std::vector<int> &sortedInts, int start, int end, int target) {
    if (start > end)
        return start;

    int middle = (start + end) / 2;

    if (sortedInts[middle] == target)
        return middle;
    else if (sortedInts[middle] > target)
        return binaryInsertionIndex(sortedInts, start, middle - 1, target);
    else
        return binaryInsertionIndex(sortedInts, middle + 1, end, target);
}

std::vector<int> getJacobsthalNumbers(int size) {
    std::vector<int> jacob;
    if (size <= 0) return jacob;
    
    jacob.push_back(0);
    if (size == 1) return jacob;

    int j0 = 0;
    int j1 = 1;
    int next;

    while (j1 < size) {
        jacob.push_back(j1);
        next = j1 + 2 * j0;
        j0 = j1;
        j1 = next;
    }
    return jacob;
}

void insert(std::vector<int> &main, int pendVal) {
    int index = binaryInsertionIndex(main, 0, main.size() - 1, pendVal);
    main.insert(main.begin() + index, pendVal);
}

std::vector<std::vector<int> > makePairs(const std::vector<int> &input) {
    std::vector<std::vector<int> > output;
    for (size_t i = 0; i < input.size(); i += 2) {
        std::vector<int> pair;
        pair.push_back(input[i]);
        if (i + 1 < input.size())
            pair.push_back(input[i + 1]);
        if (pair.size() == 2 && pair[0] < pair[1])
            std::swap(pair[0], pair[1]);
        output.push_back(pair);
    }
    return output;
}

std::vector<std::vector<int> > extractMainAndPend(std::vector<std::vector<int> > &pairsVector) {
    std::vector<int> main;
    std::vector<int> pend;
    for (size_t i = 0; i < pairsVector.size(); ++i) {
        if (pairsVector[i].size() == 2) {
            main.push_back(pairsVector[i][0]);
            pend.push_back(pairsVector[i][1]);
        } else {
            main.push_back(pairsVector[i][0]);
        }
    }
    std::vector<std::vector<int> > result;
    result.push_back(main);
    result.push_back(pend);
    return result;
}

std::vector<int> FordJohnsonAlgo(std::vector<int> &input) {
    if (input.size() <= 1)
        return input;

    std::vector<std::vector<int> > pairs = makePairs(input);
    std::vector<std::vector<int> > mainAndPend = extractMainAndPend(pairs);
    std::vector<int> pend = mainAndPend[1];
    std::vector<int> main = FordJohnsonAlgo(mainAndPend[0]);

    std::vector<int> jacobSeq = getJacobsthalNumbers(pend.size());
    std::set<int> insertedIndices;

    // First insert Jacobsthal numbers
    for (size_t i = 0; i < jacobSeq.size(); ++i) {
        int index = jacobSeq[i];
        if (index < pend.size() && insertedIndices.find(index) == insertedIndices.end()) {
            insert(main, pend[index]);
            insertedIndices.insert(index);
        }
    }

    // Then insert remaining elements in reverse order
    for (int i = pend.size() - 1; i >= 0; --i) {
        if (insertedIndices.find(i) == insertedIndices.end()) {
            insert(main, pend[i]);
            insertedIndices.insert(i);
        }
    }

    return main;
}

void printVector(const std::vector<int> &vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i < vec.size() - 1)
            std::cout << ", ";
    }
    std::cout << std::endl;
}


int main(int argc, char *argv[]) {
	struct timeval 	start;
	struct timeval 	end;
	long 			elapsedInMS;
	if (argc < 2)
		return (0);
	std::cout << "===========================================================================\n";
	try {
		Parsing<std::vector<int> > p(argv+1);
		std::vector<int> l = p.inputParse(argc - 1);
		std::cout << "Unsorted Numbers:\t" << p;
		std::cout << "===========================================================================\n";
		std::cout << "Sorted Numbers:\t\t";
		gettimeofday(&start, NULL);
		std::vector<int> sorted = FordJohnsonAlgo(l);
		gettimeofday(&end, NULL);
		printVector(sorted);
		elapsedInMS = end.tv_usec - start.tv_usec;
		std::cout << "===========================================================================\n";
		std::cout << "The Program Took (" << elapsedInMS << "ms) to Sort [" << argc - 1 << "] numbers\n"; 
	} catch (const std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
		return (1);
	}
	std::cout << "===========================================================================\n";
	return (0);
}