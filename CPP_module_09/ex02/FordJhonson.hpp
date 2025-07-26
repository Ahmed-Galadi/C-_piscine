#pragma once

#include <vector>

template<typename Container>
int binaryInsertionIndex(const Container &sortedInts, int start, int end, int target);

template<typename Container>
void insert(Container &main, int value);

template<typename Container>
std::vector<std::vector<int> > makePairs(const Container &input);

std::vector<int> getJacobsthalNumbers(int size);
std::vector<std::vector<int> > extractMainAndPend(std::vector<std::vector<int> > &pairsVector);

template<typename Container>
Container FordJohnsonAlgo(Container &input);

#include "FordJhonson.tpp"