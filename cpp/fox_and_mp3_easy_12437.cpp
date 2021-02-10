#include <algorithm>
#include <iterator>
#include <iostream>

#include <vector>
#include <string>

class FoxAndMp3Easy {
private:
    void findFilesDFS(int num, std::vector<std::string>& files, int limit);
public:
    std::vector<std::string> playList(int n);
};

std::vector<std::string> FoxAndMp3Easy::playList(int n) {
    std::vector<std::string> mp3Files;
    for(int i = 1; i <= 9 && i <= n; ++i) {
        if(mp3Files.size() == 50) {
            break;
        }
        mp3Files.push_back(std::to_string(i) + ".mp3");
        findFilesDFS(i, mp3Files, n);
    }
    return mp3Files;
}

void FoxAndMp3Easy::findFilesDFS(int num, std::vector<std::string>& files, int limit) {
    for(int i = 0; i <= 9; ++i) {
        int newNum = num * 10 + i;
        if(newNum <= limit) {
            if(files.size() == 50) {
                break;
            }
            files.push_back(std::to_string(newNum) + ".mp3");
            findFilesDFS(newNum, files, limit);
        }
        else {
            break;
        }
    }
}

int main() {
    FoxAndMp3Easy f;
    std::vector<std::string> res = f.playList(32);
    std::copy(res.begin(), res.end(), std::ostream_iterator<std::string>(std::cout, " "));
}