#pragma once

#include <vector>

template<typename Iterator>
Iterator binaryInsertionPosition(Iterator first, Iterator last, int value);

template<typename Container>
void insert(Container &main, int value);

template<typename Container>
std::vector<std::vector<int> > makePairsBiderect(const Container &input);

template<typename Container>
Container FordJohnsonAlgoBidirect(Container &input);

#include "FordJhonsonBidirect.tpp"