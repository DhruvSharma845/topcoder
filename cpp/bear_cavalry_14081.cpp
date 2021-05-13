#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using lli = long long int;

class BearCavalry {
private:
    auto findLargestThatIsUnderBraveBeart(int warrior, const std::vector<int>& horses, int bravebeart) -> int {
        auto low = int{0};
        auto high = static_cast<int>(horses.size() - 1);
        auto ans = -1; 
        while(low <= high) {
            auto mid = low + (high - low) / 2;
            if((warrior * horses[mid]) < bravebeart) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }
public:
    int countAssignments(std::vector<int>& warriors, std::vector<int>& horses) {
        std::sort(horses.begin(), horses.end());
        std::sort(warriors.begin() + 1, warriors.end(), std::greater<int>());

        auto assignments = lli{0};
        for(auto i = static_cast<int>(horses.size() - 1); i >= 0; --i) {
            auto bravebeart = warriors[0] * horses[i];
            
            std::vector<int> trimmedHorses;
            if(i != 0) {
                std::copy(horses.begin(), horses.begin() + i, std::back_inserter(trimmedHorses));
            }
            if(i != horses.size() - 1) {
                std::copy(horses.begin() + i + 1, horses.end(), std::back_inserter(trimmedHorses));
            }
            /*std::cout << "Trimmed Horses: " << std::endl;
            for(auto elem: trimmedHorses) {
                std::cout << elem << std::endl;
            }*/
            auto currentAssignments = lli{1};
            for(auto j = 1; j < warriors.size(); ++j) {
                auto perm = findLargestThatIsUnderBraveBeart(warriors[j], trimmedHorses, bravebeart);
                if(perm == -1) {
                    currentAssignments = 0;
                    break;
                }
                currentAssignments *= (perm + 1 - j + 1);
                currentAssignments = currentAssignments % 1000000007;
            }
            assignments = (assignments + currentAssignments) % 1000000007;
            //std::cout << i << " -> " << assignments << std::endl;
        }
        return assignments;
    }
};

auto main() -> int {
    BearCavalry bc;
    std::vector<int> w{970,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,
800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800};
    std::vector<int> h{1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,1000,1000,1000,1000};
    std::cout << bc.countAssignments(w, h) << std::endl;
} 


// 5 8 8 4
// 19 20 25 40
// bb = 200
