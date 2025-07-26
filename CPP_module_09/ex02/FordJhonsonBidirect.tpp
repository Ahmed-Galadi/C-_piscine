#include <vector>
#include <set>
#include <iterator>
#include "FordJhonson.hpp"

// Helper function for binary insertion index with bidirectional iterators
template<typename Iterator>
Iterator binaryInsertionPosition(Iterator first, Iterator last, int value) {
    typedef typename std::iterator_traits<Iterator>::difference_type diff_t;

    diff_t len = std::distance(first, last);
    if (len == 0)
        return first;

    diff_t mid = len / 2;
    Iterator midIt = first;
    std::advance(midIt, mid);

    if (*midIt == value)
        return midIt;
    else if (*midIt > value)
        return binaryInsertionPosition(first, midIt, value);
    else
        return binaryInsertionPosition(std::next(midIt), last, value);
}

template<typename Container>
void insertBidirect(Container &main, int value) {
    typename Container::iterator pos = binaryInsertionPosition(main.begin(), main.end(), value);
    main.insert(pos, value);
}

template<typename Container>
std::vector<std::vector<int> > makePairsBiderect(const Container &input) {
    std::vector<std::vector<int> > output;
    typename Container::const_iterator it = input.begin();

    while (it != input.end()) {
        std::vector<int> pair;
        pair.push_back(*it);
        ++it;
        if (it != input.end()) {
            pair.push_back(*it);
            ++it;
        }
        if (pair.size() == 2 && pair[0] < pair[1])
            std::swap(pair[0], pair[1]);
        output.push_back(pair);
    }
    return output;
}

template<typename Container>
Container FordJohnsonAlgoBidirect(Container &input) {
    if (input.size() <= 1)
        return input;

    std::vector<std::vector<int> > pairs = makePairsBiderect(input);
    std::vector<std::vector<int> > mainAndPend = extractMainAndPend(pairs);
    std::vector<int> pend = mainAndPend[1];

    Container main(mainAndPend[0].begin(), mainAndPend[0].end());
    main = FordJohnsonAlgoBidirect(main);

    std::vector<int> jacobSeq = getJacobsthalNumbers(pend.size());
    std::set<int> insertedIndices;

    for (size_t i = 0; i < jacobSeq.size(); ++i) {
        size_t index = jacobSeq[i];
        if (index < pend.size() && insertedIndices.find(index) == insertedIndices.end()) {
            insertBidirect(main, pend[index]);
            insertedIndices.insert(index);
        }
    }
    for (int i = pend.size() - 1; i >= 0; --i) {
        if (insertedIndices.find(i) == insertedIndices.end()) {
            insertBidirect(main, pend[i]);
            insertedIndices.insert(i);
        }
    }
    return main;
}