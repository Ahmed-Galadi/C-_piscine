#include <vector>

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

std::vector<std::vector<int> > extractMainAndPend(std::vector<std::vector<int> > &pairsVector) {
    std::vector<int> main;
    std::vector<int> pend;
    for (std::size_t i = 0; i < pairsVector.size(); ++i) {
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
