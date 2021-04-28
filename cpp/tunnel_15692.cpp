#include <iostream>
#include <vector>
#include <string>
#include <limits>

class Tunnel {
private:
    void processNextRow(const std::vector<std::string>& level, int rate, int currentRow, std::vector<std::vector<int>>& visited);
    void markInRange(const std::vector<std::string>& level, int columns, int currentRow, int currentCol, int rate, std::vector<std::vector<int>>& visited);
public:
    int minKeystrokes(const std::vector<std::string>& level, int rate);
};

int Tunnel::minKeystrokes(const std::vector<std::string>& level, int rate) {
    auto maxInt = std::numeric_limits<int>::max();
    int startingIndex = -1;
    for (int i = 0; i < level[0].length(); ++i) {
        if(level[0][i] == 'v') {
            startingIndex = i;
            break;
        }
    }
    auto rows{level.size()};
    auto cols{level[0].length()};
    std::vector<std::vector<int>> visited(rows, std::vector<int>(cols, maxInt));
    visited[0][startingIndex] = 0;

    markInRange(level, cols, 0, startingIndex, rate, visited);
    /*for(auto row: visited) {
        for(auto elem: row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }*/

    for(int i = 1; i < rows; ++i) {
        processNextRow(level, rate, i, visited);
    }
    auto minVal = std::numeric_limits<int>::max();
    for(auto elem: visited[level.size() - 1]) {
        if(elem != maxInt) {
            minVal = std::min(minVal, elem);
        }
    }
    return (minVal != maxInt ? minVal : -1);
}

void Tunnel::markInRange(const std::vector<std::string>& level, int columns, int currentRow, int currentCol, int rate, std::vector<std::vector<int>>& visited) {
    for(auto i = 1; i <= rate; ++i) {
        //+
        auto nextCol = currentCol + i;
        if(nextCol < columns && level[currentRow][nextCol] == '.' && visited[currentRow][currentCol + i - 1] + 1 < visited[currentRow][nextCol]) {
            visited[currentRow][nextCol] = visited[currentRow][currentCol + i - 1] + 1;
        }
        //-
        nextCol = currentCol - i;
        if(nextCol >= 0 && level[currentRow][nextCol] == '.' && visited[currentRow][currentCol - i + 1] + 1 < visited[currentRow][nextCol]) {
            visited[currentRow][nextCol] = visited[currentRow][currentCol - i + 1] + 1;
        }
    }
}

void Tunnel::processNextRow(const std::vector<std::string>& level, int rate, int currentRow, std::vector<std::vector<int>>& visited) {
    for(auto i = 0; i < level[0].length(); ++i) {
        if(level[currentRow][i] == '.') {
            if(visited[currentRow - 1][i] != std::numeric_limits<int>::max()) {
                visited[currentRow][i] = std::min(visited[currentRow][i], visited[currentRow - 1][i]);
                markInRange(level, level[0].length(), currentRow, i, rate, visited);
            }
        }
    }
}

auto main() -> int {
    Tunnel t;
    std::vector<std::string> keyStrokes{"##..v..##",
 "###.....#",
 "#####...#",
 "####...##",
 "###..####",
 "#.......#",
 "#...#####"};
    std::cout << t.minKeystrokes(keyStrokes, 2) << std::endl;
}