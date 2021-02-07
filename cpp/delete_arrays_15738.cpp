#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <numeric>

class DeleteArrays {
public:
    std::vector<long long int> doDelete(int a, int b, int c, long x, long y, long z);
};

std::vector<long long int> DeleteArrays::doDelete(int a, int b, int c, long x, long y, long z) {
    std::vector<long long int> A(a, 0);
    std::vector<long long int> B(b, 0);
    std::vector<long long int> C(c, 0);

    A[0] = 33;
    A[1] = 42;
    for (size_t i = 2; i < a; ++i) {
        A[i] = (5 * A[i-1] + 7 * A[i-2]) % 1000000007 + 1;
    }
    
    B[0] = 13;
    for (size_t i = 1; i < b; ++i) {
        B[i] = (11 * B[i-1]) % 1000000007 + 1;
    }

    C[0] = 7;
    C[1] = 2;
    for (size_t i = 2; i < a; ++i) {
        C[i] = (5 * C[i-1] + 7 * C[i-2]) % 1000000007 + 1;
    }

    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());
    std::sort(C.begin(), C.end());

    std::vector<std::pair<int, std::vector<long long int>*>> collection;
    collection.push_back(std::make_pair(0, &A));
    collection.push_back(std::make_pair(1, &B));
    collection.push_back(std::make_pair(2, &C));

    long long int sum = 0;
    while(true) {
        int count = 0;
        if(A.size() == 0) {
            ++count;
        } 
        if(B.size() == 0) {
            ++count;
        } 
        if(C.size() == 0) {
            ++count;
        }
        if(count > 1) {
            break;
        }
        for(int i = 0; i < 3; ++i) {
            if(collection[i].second->size() == 0) {
                collection.erase(collection.begin() + i);
            }
        }
        //std::cout << collection.size() << std::endl;
        std::sort(collection.begin(), collection.end(), [](const std::pair<int, std::vector<long long int>*>& a, const std::pair<int, std::vector<long long int>*>& b) {
            if(a.second->size() != b.second->size()) {
                return a.second->size() < b.second->size();
            }
            else {
                return a.second->back() < b.second->back();
            }
        });
        //std::cout << collection[0].first << " " << collection[1].first << " " << collection[2].first << std::endl;
        std::pair<int, std::vector<long long int>*> first = collection.back();
        std::pair<int, std::vector<long long int>*> second = collection.at(collection.size() - 2);
        if((first.first == 0 && second.first == 1) || (first.first == 1 && second.first == 0)) {
            sum += (x + first.second->back() + second.second->back());
            first.second->pop_back();
            second.second->pop_back(); 
        }
        else if((first.first == 1 && second.first == 2) || (first.first == 2 && second.first == 1)) {
            sum += (y + first.second->back() + second.second->back());
            first.second->pop_back();
            second.second->pop_back(); 
        }  
        else if((first.first == 2 && second.first == 0) || (first.first == 0 && second.first == 2)) {
            sum += (z + first.second->back() + second.second->back());
            first.second->pop_back();
            second.second->pop_back(); 
        }       
    }
    long long int remaining_sum1 = 0;
    for(long long int elem: A) {
        remaining_sum1 += elem;
    }
    long long int remaining_sum2 = 0;
    for(long long int elem: B) {
        remaining_sum2 += elem;
    }
    long long int remaining_sum3 = 0;
    for(long long int elem: C) {
        remaining_sum3 += elem;
    }
    return {(remaining_sum1+remaining_sum2+remaining_sum3), sum};
}

int main() {
    DeleteArrays da;
    std::vector<long long int> res = da.doDelete(100000, 5, 8, 424242, 474747, 123456789);
    std::cout << res[0] << " " << res[1] << std::endl;
}