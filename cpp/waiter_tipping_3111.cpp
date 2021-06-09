#include <iostream>
#include <cmath>

class WaiterTipping {
public:
    int maxPercent(int total, int taxPercent, int money) {
        int totalWithTax = total + std::floor((total * taxPercent) / 100);
        int remaining = money - totalWithTax;
        if(remaining < 0) {
            return -1;
        }
        //std::cout << "rem: " << remaining << std::endl;
        int tip = std::floor((static_cast<double>(remaining) * 100) / total);
        if(std::floor(((tip + 1) * total) / 100) <= remaining) {
            return tip + 1;
        }
        return tip;
    }
};

auto main() -> int {
    WaiterTipping wt;
    std::cout << wt.maxPercent(500, 10, 550) << std::endl;
}