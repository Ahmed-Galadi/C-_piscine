	#include <vector>
	#include <set>

	template<typename Container>
	int binaryInsertionIndex(const Container &sortedInts, int start, int end, int target) {
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

	template<typename Container>
	void insert(Container &main, int value) {
		int index = binaryInsertionIndex(main, 0, main.size() - 1, value);
		main.insert(main.begin() + index, value);
	}

	template<typename Container>
	std::vector<std::vector<int> > makePairs(const Container &input) {
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

	template<typename Container>
	Container FordJohnsonAlgo(Container &input) {
		if (input.size() <= 1)
			return input;

		std::vector<std::vector<int> > pairs = makePairs(input);
		std::vector<std::vector<int> > mainAndPend = extractMainAndPend(pairs);
		std::vector<int> pend = mainAndPend[1];

		Container main(mainAndPend[0].begin(), mainAndPend[0].end());
		main = FordJohnsonAlgo(main);

		std::vector<int> jacobSeq = getJacobsthalNumbers(pend.size());
		std::set<int> insertedIndices;
		// First insert Jacobsthal numbers
		for (size_t i = 0; i < jacobSeq.size(); ++i) {
			size_t index = jacobSeq[i];
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