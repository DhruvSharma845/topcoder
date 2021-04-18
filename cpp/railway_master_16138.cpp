#include <iostream>
#include <vector>
#include <algorithm>

class UnionFind {
public:
    explicit UnionFind(int size);
    int find(int x);
    void unite(int x, int y);
    bool isConnected(int x, int y);
private:
    std::vector<int> parent;
};

UnionFind::UnionFind(int size) {
    parent.reserve(size);
    for (auto i = 0; i < size; ++i) {
        parent[i] = i;
    }
}

int UnionFind::find(int x) {
    while(parent[x] != x) {
        x = parent[x];
    }
    return x;
}

void UnionFind::unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    parent[rootX] = rootY; 
}

bool UnionFind::isConnected(int x, int y) {
    return (find(x) == find(y));
}

struct Edge {
    int x;
    int y;
    int weight;
    Edge(int _x, int _y, int _weight): x{_x}, y{_y}, weight{_weight} {}
};

class RailwayMaster {
public: 
    int maxProfit(int N, int M, int K, const std::vector<int>& a, const std::vector<int>& b, const std::vector<int>& v);
};

int RailwayMaster::maxProfit(int N, int M, int K, const std::vector<int>& a, const std::vector<int>& b, const std::vector<int>& v) {
    std::vector<Edge> edges;
    for (int i = 0; i < M; ++i) {
        edges.emplace_back(a[i], b[i], v[i]);
    }
    
    std::sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    UnionFind uf{N};
    std::vector<int> edgesThatCanBeRemoved;
    for(int i = 0; i < M; ++i) {
        const auto& edge = edges[i];
        if(uf.isConnected(edge.x, edge.y) == true) {
            edgesThatCanBeRemoved.push_back(i);
        } else {
            uf.unite(edge.x, edge.y);
        }
    }

    int finalSum = 0;
    int sz = edgesThatCanBeRemoved.size();
    for (int i = 0; i < K && i < sz; ++i) {
        finalSum += (edges[edgesThatCanBeRemoved[sz - i - 1]].weight);
    }
    return finalSum;
}

auto main() -> int {
    RailwayMaster rm;
    std::vector<int> a{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4};
    std::vector<int> b{1, 2, 3, 4, 0, 6, 7, 8, 9, 5, 5, 6, 7, 8, 9};
    std::vector<int> v{220284, 869120, 787788, 980412, 133333, 314159, 256312, 192916, 298575, 931110, 175353, 926778, 201513, 202729, 155136};
    std::cout << rm.maxProfit(10, 15, 3, a, b, v) << std::endl;
}