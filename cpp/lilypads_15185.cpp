#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

class Lilypads {
private:
    void traverse_row(int C, int currentRow, int startingCol, std::vector<int>& path);
public:
    std::vector<int> traverse(int R, int C, int r0, int c0);
};

std::vector<int> Lilypads::traverse(int R, int C, int r0, int c0) {
    std::vector<int> path;

    int currentCol = c0;
    int currentRow = r0;
    std::vector<int> visited(R, 0);

    int upInd = 0;
    int downInd = R - 1;
    bool fromUp = true;
    if(currentRow == 0) {
        fromUp = false;
    }
    for(int i = 0; i < R; ++i) {
        traverse_row(C, currentRow, currentCol, path);
        // find next row
        if(fromUp == true) {
            while(upInd < R && upInd < downInd && (upInd == r0 || visited[upInd] == 1)) {
                ++upInd;
            } 
            visited[upInd] = 1;
            currentRow = upInd;
        }
        else {
            while(downInd >= 0 && downInd > upInd && (downInd == r0 || visited[downInd] == 1)) {
                --downInd;
            } 
            visited[downInd] = 1;
            currentRow = downInd;
        }
        // starting col of this row
        currentCol = path.back();
    }
    
    return path;
}

void Lilypads::traverse_row(int C, int currentRow, int startingCol, std::vector<int>& path) {
    int leftInd = 0;
    int rightInd = C - 1;
    std::vector<int> visited(C, 0);

    path.push_back(currentRow);
    path.push_back(startingCol);
    bool fromLeft = true;
    if(startingCol == 0) {
        fromLeft = false;
    }
    
    for(int i = 0; i < C - 1; ++i) {
        if(fromLeft == true) {
            while(leftInd < C && leftInd < rightInd && (leftInd == startingCol || visited[leftInd] == 1)) {
                ++leftInd;
            } 
            path.push_back(currentRow);
            path.push_back(leftInd);
            visited[leftInd] = 1;
        }
        else {
            while(rightInd >= 0 && rightInd > leftInd && (rightInd == startingCol || visited[rightInd] == 1)) {
                --rightInd;
            } 
            path.push_back(currentRow);
            path.push_back(rightInd);
            visited[rightInd] = 1;
        }
        fromLeft = !fromLeft;
    }
}

int main() {
    Lilypads lp;
    std::vector<int> res = lp.traverse(3, 3, 1, 2);
    std::copy(res.begin(), res.end(), std::ostream_iterator<int>(std::cout, " "));
}