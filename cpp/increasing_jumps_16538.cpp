#include <iostream>
#include <vector>
#include <cstdlib>

class IncreasingJumps {
public:
    std::vector<int> jump(std::vector<int>& frogs) {
        std::vector<int> result;
        for (size_t i = 0; i < frogs.size(); i++) {
            auto direction = 1;
            int diff = abs(frogs[i] - static_cast<int>(i));
            if(frogs[i] < i) {
                direction = -1;
            }

            for (auto j = 0; j < diff; j++) {
                result.push_back(direction * (i+1));
                result.push_back(-direction * (i+1));
            } 
        }
        return result;
    }
};

auto main() -> int {
    IncreasingJumps ij;
    std::vector<int> v{5, 6, 1, 9, 8};
    auto res = ij.jump(v);
    std::copy(res.begin(), res.end(), std::ostream_iterator<int>(std::cout, " "));
}