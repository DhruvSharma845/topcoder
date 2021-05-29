#include <iostream>
#include <cmath>

class EmoticonsDiv2 {
private:
    int greatestMultiple(int num) {
        auto index = 2;
        int sqrtNum = static_cast<int>(sqrt(num));
        while(index <= sqrtNum && num % index != 0) {
            index++;
        }
        return (index > sqrtNum) ? 1 : num / index;
    }
public:
    int printSmiles(int smiles) {
        auto res = int{0};
        while(smiles != 1) {
            auto multipleNum = greatestMultiple(smiles);
            res += (smiles / multipleNum);
            smiles = multipleNum;
        }
        return res;
    }
};

auto main() -> int {
    EmoticonsDiv2 ed;
    std::cout << ed.printSmiles(11) << std::endl;

}

/*
1000
500 -> 2
250 -> 2
125 -> 2   50 -> 6
25 -> 5    25 -> 2
5 -> 5     4 -> 6
1 -> 5     1  -> 4
*/