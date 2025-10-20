#include <algorithm>
#include <vector>
#include <iterator>
#include <iostream>

template <typename T>
int	easyfind(T &container, int toFind) {
	typename T::iterator iter = std::find(container.begin(), container.end(), toFind);
    if (iter != container.end()) {
        return (std::distance(container.begin(), iter));
    }
	return (-1);
}
