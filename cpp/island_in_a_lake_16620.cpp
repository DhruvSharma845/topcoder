#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <utility>

class IslandInALake {
private:
    void fillSea(std::vector<std::string>& country);
    int findIsland(std::vector<std::string>& country);
    int findIslandUtil(std::vector<std::string>& country, int row, int col, std::vector<std::vector<bool>>& visited);
    bool isValid(std::vector<std::string>& country, int row, int col);
public:
    int build(std::vector<std::string>& country);
};

int IslandInALake::build(std::vector<std::string>& country) {
    fillSea(country);
    int res = findIsland(country);
    std::copy(country.begin(), country.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
    return res;
}

bool IslandInALake::isValid(std::vector<std::string>& country, int row, int col) {
    std::vector<int> rowInc{-1, -1, -1, 0, 0, 0, 1, 1, 1};
    std::vector<int> colInc{-1, 0, 1, -1, 0, 1, -1, 0, 1};

    for (int i = 0; i < rowInc.size(); ++i) {
        int nextRow = row + rowInc[i];
        int nextCol = col + colInc[i];
        if(nextRow >= 0 && nextRow < country.size() && nextCol >=0 && nextCol < country[0].length() && (country[nextRow][nextCol] == '#' || country[nextRow][nextCol] == '*')) {
            return false;
        }
    }
    return true;
}

int IslandInALake::findIsland(std::vector<std::string>& country) {
    int maxIsland = 0;
    std::vector<std::vector<bool>> visited(country.size(), std::vector<bool>(country[0].length(), false));
    for (int i = 0; i < country.size(); ++i)
    {
        for (int j = 0; j < country[0].length(); ++j)
        {
            if(country[i][j] == '.' && visited[i][j] == false && isValid(country, i, j)) {
                visited[i][j] = true;
                maxIsland = std::max(maxIsland, findIslandUtil(country, i, j, visited));
            }
        }
    }
    return maxIsland;
}

int IslandInALake::findIslandUtil(std::vector<std::string>& country, int row, int col, std::vector<std::vector<bool>>& visited) {
    int count = 1;
    std::queue<std::pair<int, int>> que;
    que.emplace(row, col);

    std::vector<int> rowInc{-1, -1, -1, 0, 0, 0, 1, 1, 1};
    std::vector<int> colInc{-1, 0, 1, -1, 0, 1, -1, 0, 1};

    while(!que.empty()) {
        std::pair<int, int> fr = que.front();
        //std::cout << fr.first << " " << fr.second << std::endl;
        que.pop();
        for (int i = 0; i < rowInc.size(); ++i) {
            int nextRow = fr.first + rowInc[i];
            int nextCol = fr.second + colInc[i];
            if(country[nextRow][nextCol] == '.' && visited[nextRow][nextCol] == false && isValid(country, nextRow, nextCol)) {
                visited[nextRow][nextCol] = true;
                ++count;
                que.emplace(nextRow, nextCol);
            }
        }
    }
    return count;
}

void IslandInALake::fillSea(std::vector<std::string>& country) {
    int numRows = country.size();
    int numCols = country[0].length();
    
    // Using BFS
    std::queue<std::pair<int, int>> que;

    std::vector<std::vector<bool>> visited(numRows, std::vector<bool>(numCols, false));

    que.emplace(0,0);

    while(!que.empty()) {
        std::pair<int, int> fr = que.front();
        que.pop();

        country[fr.first][fr.second] = '*';
        visited[fr.first][fr.second] = true;

        std::vector<int> rowInc{-1, 0, 1, 0};
        std::vector<int> colInc{0, 1, 0, -1};
        for(int i = 0; i < rowInc.size(); ++i) {
            int nextRow = fr.first + rowInc[i];
            int nextCol = fr.second + colInc[i];
            if(nextRow >=0 && nextRow < numRows && nextCol >= 0 && nextCol < numCols && country[nextRow][nextCol] == '.' && visited[nextRow][nextCol] == false) {
                que.emplace(nextRow, nextCol);
            }
        } 
    }
}

int main() {
    IslandInALake il;
    std::vector<std::string> country{
    /*    "..........",
        ".####.....",
        ".#...#....",
        ".#...#....",
        ".#...#....",
        ".#####....",
        ".........."*/
       "............",
 ".####.#####.",
 ".#...#....#.",
 ".#........#.",
 ".#...#....#.",
 ".#########..",
 "............"
    };
    std::cout << il.build(country) << std::endl;
}