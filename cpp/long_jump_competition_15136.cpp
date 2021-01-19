#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <utility>
#include <functional>

class LongJumpCompetition {
public:
    std::vector<int> recoverStandings(std::vector<int>& jumpLengths);
};

std::vector<int> LongJumpCompetition::recoverStandings(std::vector<int>& jumpLengths) {
    int contestants = jumpLengths.size() / 3;

    std::vector<std::pair<int, std::vector<int>>> currentDistances;
    for(int i = contestants - 1; i >= 0; --i) {
        std::vector<int> v;
        v.push_back(jumpLengths[contestants - i - 1]);
        currentDistances.emplace_back(i, v);
    }

    for(int i = 1; i < 3; ++i) {
        std::sort(currentDistances.begin(), currentDistances.end(), [](const std::pair<int, std::vector<int>>& a, const std::pair<int, std::vector<int>>& b) {
            for(int k = 0; k < a.second.size(); ++k) {
                if(a.second[k] == b.second[k]) {
                    continue;
                }
                return a.second[k] < b.second[k];
            }
            // small bib is better(so descending order)
            return a.first > b.first;
        });

        for(auto elem: currentDistances) {
            std::cout << elem.first << " " << elem.second.size() << std::endl;
        }
        std::cout << std::endl;

        for(int j = 0; j < contestants; ++j) {
            currentDistances[j].second.push_back(jumpLengths[i * contestants + j]);
            std::sort(currentDistances[j].second.begin(), currentDistances[j].second.end(), std::greater<int>()); 
        }
    }
    std::sort(currentDistances.begin(), currentDistances.end(), [](const std::pair<int, std::vector<int>>& a, const std::pair<int, std::vector<int>>& b) {
        for(int k = 0; k < a.second.size(); ++k) {
            if(a.second[k] == b.second[k]) {
                continue;
            }
            return a.second[k] < b.second[k];
        }
        // small bib is better(so descending order)
        return a.first > b.first;
    });

    std::vector<int> res;
    for(auto elem = currentDistances.rbegin(); elem != currentDistances.rend(); ++elem) {
        res.push_back((*elem).first);
    }
    return res;
}

int main() {
    LongJumpCompetition ljc;
    std::vector<int> v{850, 840, 841, 850, 850, 837};
    std::vector<int> res = ljc.recoverStandings(v);
    std::copy(res.begin(), res.end(), std::ostream_iterator<int>(std::cout, " "));
}