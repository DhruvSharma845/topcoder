#include <iostream>
#include <vector>
#include <cmath>

class PillarsDivTwo {
public:
    double maximalLength(std::vector<int>& height, int w) {
        int numOfPillars = height.size();
        std::vector<std::vector<double>> table(numOfPillars, std::vector<double>(2, 0.0));

        table[0][0] = 0.0;
        table[0][1] = 0.0;
        for (auto i = 1; i < numOfPillars; i++) {
            double cachedWidth = pow(w, 2);
            // for min height
            double ropeWithPrevMin = w + table[i-1][0];
            double ropeWithPrevMax = table[i-1][1] + sqrt(cachedWidth + pow(height[i-1] - 1, 2));
            table[i][0] = std::max(ropeWithPrevMin, ropeWithPrevMax);
            
            // for max height
            ropeWithPrevMin = table[i-1][0] + sqrt(cachedWidth + pow(height[i] - 1, 2));
            ropeWithPrevMax = table[i-1][1] + sqrt(cachedWidth + pow(abs(height[i] - height[i-1]), 2));
            table[i][1] = std::max(ropeWithPrevMin, ropeWithPrevMax);
        }
        return std::max(table[numOfPillars - 1][0], table[numOfPillars - 1][1]);
    }
};

auto main() -> int {
    std::vector<int> v{2,1,1,2};
    PillarsDivTwo pdt;
    std::cout << pdt.maximalLength(v, 1) << std::endl;
}