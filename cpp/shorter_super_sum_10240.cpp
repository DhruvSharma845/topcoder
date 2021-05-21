#include <vector>
#include <iostream>

class ShorterSuperSum {
public:
    int calculate(int k, int n) {
        std::vector<std::vector<int>> table(k + 1, std::vector<int>(n + 1, 0));
        for (auto i = 0; i <= n; i++) {
            table[0][i] = i;
        }
        for (auto i = 1; i <= k; i++) {
            for(auto j = 0; j <= n; j++) {
                auto sum = int{0};
                for (auto m = 1; m <= j; m++) {
                    sum += table[i - 1][m];
                }
                table[i][j] = sum;
            }
        }
        return table[k][n];
    }
};

auto main() -> int {
    ShorterSuperSum sss;
    std::cout << sss.calculate(14, 14) << std::endl;
}