#include <iostream>
#include <string>
#include <vector>
#include <set>

class CompletelyDifferentStrings {
public:
    int count(int S, std::vector<std::string>& forbidden);
};

int CompletelyDifferentStrings::count(int S, std::vector<std::string>& forbidden) {
    auto numStrings = int{1};
    for(auto i = 0; i < forbidden[0].length(); ++i) {
        std::set<char> uniq_chars;
        for(auto j = 0; j < forbidden.size(); ++j) {
            uniq_chars.insert(forbidden[j][i]);
        }
        numStrings *= (S - uniq_chars.size());
    }
    return numStrings;
}

auto main() -> int {
    CompletelyDifferentStrings cds;
    std::vector<std::string> forbidden{"abacaa", "abacaa", "acabab"};
    std::cout << cds.count(3, forbidden) << std::endl;
}