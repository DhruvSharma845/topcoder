#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

class FakeReportData {
public:
    std::vector<int> generate(int N, int D) {
        std::vector<int> nums(N, 0);
        for (size_t i = 1; i <= N; i++) {
            std::string s;
            char c = static_cast<char>(i + 48);
            s.push_back(c);
            for (size_t j = 1; j < D; j++) {
                int num = (i + j) % 10;
                char c = static_cast<char>(num + 48);
                s.push_back(c);
            }
            nums[i - 1] = std::stoi(s);
        }
        return nums;
    }
};

auto main() -> int {
    FakeReportData frd;
    std::vector<int> v = frd.generate(7, 1);
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
}