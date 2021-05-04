#include <iostream>
#include <string>

class SyllableCountEstimator {
private:
    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    };
public:
    int estimate(const std::string& W) {
        auto syllables = 0;
        auto sz = W.length();
        for (auto i = 0; i < W.length(); ++i) {
            char ch = static_cast<char>(tolower(W[i]));
            if(isVowel(ch)) {
                ++syllables;
                if(i + 1 < sz) {
                    char nextChar = W[i + 1];
                    if((ch == 'a' && nextChar == 'u') || 
                        (ch == 'o' && nextChar == 'o') ||
                        (ch == 'o' && nextChar == 'a') ||
                        ((i+2 < sz) && ch == 'i' && nextChar == 'o' && W[i+2] == 'u')) {
                            --syllables;
                        } 
                }
            }
        }
        if(W[sz - 1] == 'e') {
            --syllables;
            if(sz > 2 && W[sz - 2] == 'l' && isVowel(W[sz - 3]) == false) {
                ++syllables;
            }
        }
        if(syllables < 1) {
            syllables = 1;
        }
        return syllables;
    }
};

auto main() -> int {
    SyllableCountEstimator sce;
    std::cout << sce.estimate("participle") << std::endl;
}