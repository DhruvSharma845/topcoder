#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

class BuyOneGetOneFree {
public:
    int buy(std::vector<int> prices);
};

int BuyOneGetOneFree::buy(std::vector<int> prices) {
    std::sort(prices.begin(), prices.end(), std::greater<int>());

    int sum = 0;
    for (int i = 0; i < prices.size(); i+=2) {
        sum += prices[i];
    }
    return sum;
}

int main() {
    BuyOneGetOneFree b;
    std::vector<int> prices{1, 2, 3, 4, 5};
    std::cout << b.buy(prices);
}