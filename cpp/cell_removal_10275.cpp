#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <queue>
#include <algorithm>

class CellRemoval {
public:
    int cellsLeft(std::vector<int>& parent, int deletedCell) {
        std::vector<bool> active(parent.size(), true);
        std::unordered_map<int, std::vector<int>> tree;
        for(size_t i = 0; i < parent.size(); i++) {
            auto elem = parent[i];
            if(elem != -1) {
                active[elem] = false;
            }
            if(tree.find(elem) == tree.end()) {
                std::vector<int> l;
                l.push_back(i);
                tree.insert(std::make_pair(elem, l));
            }
            else {
                tree[elem].push_back(i);
            }
        }
        std::queue<int> q;
        q.push(deletedCell);
        while(!q.empty()) {
            int currentCell = q.front();
            q.pop();
            active[currentCell] = false;
            if(tree.find(currentCell) != tree.end()) {
                for(const auto& child: tree[currentCell]) {
                    q.push(child);
                }
            }
        }
        return std::count(active.begin(), active.end(), true);
    }
};

auto main() -> int {
    CellRemoval cr;
    std::vector<int> v{26,2,32,36,40,19,43,24,30,13,21,14,24,21,19,4,30,10,44,12,7,32,17,43,35,18,7,36,10,16,5,38,35,4,13,-1,16,26,1,12,2,5,18,40,1,17,38,44,14};
    std::cout << cr.cellsLeft(v, 24) << std::endl;
}

/*
3 3 -1 2
2

-1,0,0,2,2,4,4,6,6
0
1  2
  3  4
    5  6
      7  8 
*/