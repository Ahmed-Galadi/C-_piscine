#include <algorithm>
#include <vector>
#include <iterator>

template <typename T>
unsigned int	easyfind(T container, int toFind) {

	std::vector<int>::iterator iter = std::find(container.begin(), container.end(), toFind);
    
    if (iter != container.end()) {
        std::cout << "Found " << toFind << " at position: " 
                  << std::distance(container.begin(), iter) << std::endl;
        std::cout << "Value: " << *iter << std::endl;
    } else
        std::cout << toFind << " not found!" << std::endl;
}
