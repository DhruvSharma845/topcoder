#include <iostream>
#include <string>
#include <bitset>

class RemovingParenthesis {
private:
    auto isBalanced(const std::string& s, const std::bitset<32>& removed) -> bool {
        auto count = int{0};
        int index = 0;
        for(const auto& ch: s) {
            if(removed.test(index) == false) {
                if(ch == '(') {
                    count++;
                }
                else if(ch == ')') {
                    count--;
                }
                if(count < 0) {
                    return false;
                }
            }
            index++;
        }
        return (count == 0);
    }
    auto countWaysUtil(const std::string& s, std::bitset<32>& removed) -> int {
        auto startingIndex = int{-1};

        auto empty = (removed.count() == s.length());
        if(empty == true) {
            return 1;
        }

        for(size_t i = 0; i < s.length(); i++) {
            if(s[i] == '(' && removed.test(i) == false) {
                removed.set(i);
                startingIndex = i;
                break;
            }
        }
        auto ways = int{0};
        if(startingIndex == -1) {
            return ways;
        }
        for (size_t i = startingIndex + 1; i < s.length(); i++) {
            if(s[i] == ')' && removed.test(i) == false) {
                removed.set(i);
                if(isBalanced(s, removed) == true) {
                    ways += countWaysUtil(s, removed);
                }
                removed.reset(i);
            }
        }
        removed.reset(startingIndex);
        return ways;
    }
public:
    int countWays(std::string& s) {
        std::bitset<32> removed;
        return countWaysUtil(s, removed);
    }
};

auto main() -> int {
    RemovingParenthesis rp;
    std::string s{"((()))(()(()))((()))"};
    std::cout << rp.countWays(s) << std::endl;
}