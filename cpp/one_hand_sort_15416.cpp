#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

class OneHandSort {
public:
    std::vector<int> sortShelf(std::vector<int> target);
};

std::vector<int> OneHandSort::sortShelf(std::vector<int> target) {
    
    std::vector<int> steps;
    int extraPos = -1;
    for(int currentIndex = 0; currentIndex < target.size(); ++currentIndex) {
        int i = currentIndex;
        if(i != target[i]) {
            extraPos = target[i];
            steps.push_back(i);
            while(i != extraPos && i != target[i]) {
                int j = 0;
                for(; j < target.size(); ++j) {
                    if(target[j] == i) {
                        break;
                    }
                }
                target[i] = i;
                i = j;
                steps.push_back(j);
            }
            if(i == extraPos) {
                target[i] = i;
                steps.push_back(target.size());
            }
        }
    }
    return steps;
}

int main() {
    OneHandSort ohs;
    std::vector<int> arr{1, 2, 3, 0};
    std::vector<int> sortedArr = ohs.sortShelf(arr);

    std::copy(sortedArr.begin(), sortedArr.end(), std::ostream_iterator<int>(std::cout, " "));
}