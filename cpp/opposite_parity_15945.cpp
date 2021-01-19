#include <iostream>
#include <vector>
#include <iterator>

class OppositeParity {
public:
    std::vector<int> rearrange(std::vector<int>& A);
};

std::vector<int> OppositeParity::rearrange(std::vector<int>& A) {
    int MAX_VAL = 1000;

    int oddIndex = 0;
    int evenIndex = 0;

    while(true) {
        while(oddIndex < A.size() && (A[oddIndex] > MAX_VAL || A[oddIndex] % 2 == 0)) {
            ++oddIndex;
        }

        while(evenIndex < A.size() && (A[evenIndex] > MAX_VAL || A[evenIndex] % 2 != 0)) {
            ++evenIndex;
        }

        if(oddIndex >= A.size() && evenIndex >= A.size()) {
            break;
        }

        if(oddIndex >= A.size() || evenIndex >= A.size()) {
            return std::vector<int>();
        }

        int evenValue = A[evenIndex];
        int oddValue = A[oddIndex];

        A[evenIndex] = MAX_VAL + oddValue;
        A[oddIndex] = MAX_VAL + evenValue; 

        ++oddIndex;
        ++evenIndex;
    }

    for(int i = 0; i < A.size(); ++i) {
        A[i] -= MAX_VAL;
    }

    return A;
}

/**
 *  1 4 1 4 2 1
 *  
 **/
int main() {
    OppositeParity op;
    std::vector<int> v{27, 18, 281, 828, 45, 90, 452, 3};
    std::vector<int> res = op.rearrange(v);
    std::copy(res.begin(), res.end(), std::ostream_iterator<int>(std::cout, " "));
}