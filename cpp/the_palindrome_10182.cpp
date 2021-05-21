#include <iostream>
#include <string>
#include <vector>

class ThePalindrome {
public:
    auto find(const std::string& s) -> int {
        auto numOfChars = static_cast<int>(s.length());
        std::vector<std::vector<bool>> table(numOfChars, std::vector<bool>(numOfChars, false));
        for(auto i = 0; i < numOfChars; i++) {
            table[i][i] = true;
            if(i != numOfChars - 1) {
                table[i][i+1] = (s[i] == s[i+1]);
            }
        }
        for(auto diagonal = 2; diagonal < numOfChars; diagonal++) {
            for(auto row = 0; row < numOfChars - diagonal; row++) {
                auto column = row + diagonal;
                table[row][column] = table[row + 1][column - 1] && (s[row] == s[column]);
            }
        }
        auto index = -1;
        for(auto row = 0; row < numOfChars; row++) {
            if(table[row][numOfChars - 1] == true) {
                index = row;
                break;
            }
        }
        return ( 2 * index  + (numOfChars - index));
    }
};

auto main() -> int {
    ThePalindrome tp;
    std::cout << tp.find("abacaba") << std::endl;
}


/*
00 01 02 03
10 11 12 13
20 21 22 23
30 31 32 33
*/