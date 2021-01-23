#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <iostream>

class CircuitsConstruction {
private:
    int recurseOnRemainingCircuit(int* index, const std::string& circuit);
public:
    int maximizeResistance(const std::string& circuit, std::vector<int>& conductors);
};

int CircuitsConstruction::maximizeResistance(const std::string& circuit, std::vector<int>& conductors) {
    std::sort(conductors.begin(), conductors.end());
    std::unique_ptr<int> index = std::make_unique<int>(0);
    int lim = recurseOnRemainingCircuit(index.get(), circuit);
    int sz = conductors.size();
    int res = 0;
    for(int i = sz - 1; i >= sz - lim; --i) {
        res += conductors[i];
    }
    return res;
}

int CircuitsConstruction::recurseOnRemainingCircuit(int* index, const std::string& circuit) {
    if(circuit.at(*index) == 'X') {
        (*index)++;
        return 1;
    }
    else if(circuit.at(*index) == 'A') {
        (*index)++;
        return recurseOnRemainingCircuit(index, circuit) + recurseOnRemainingCircuit(index, circuit);
    }
    else {
        (*index)++;
        return std::max<int>(recurseOnRemainingCircuit(index, circuit), recurseOnRemainingCircuit(index, circuit));
    }
}
int main() {
    CircuitsConstruction cc;
    std::string s("BAAXBXXBXAXXBBAXXBXXAAXXX");
    std::vector<int> v{17, 7, 21, 102, 56, 72, 88, 15, 9, 192, 16, 8, 30};
    std::cout << cc.maximizeResistance(s, v) << std::endl;
}