#include <iostream>
#include <numeric>
#include <vector>

class Solution {
public:
  int countVowelStrings(int n) {
    std::vector<int> memo = {1, 1, 1, 1, 1};

    for (int i = 1; i < n; i++) {
      for (int j = 3; j >= 0; j--) {
        memo[j] = memo[j] + memo[j + 1];
      }
    }

    return std::accumulate(memo.begin(), memo.end(), 0);
  }
};

int main() {
  Solution solution;

  std::cout << solution.countVowelStrings(1) << std::endl;
  std::cout << solution.countVowelStrings(2) << std::endl;
  std::cout << solution.countVowelStrings(33) << std::endl;

  return 0;
}