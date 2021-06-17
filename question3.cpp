
#include <bits/stdc++.h>
using namespace std;

int solveKnapsack(const vector<int> &values, const vector<int> &weights, int capacity) {
    if (capacity <= 0 || values.empty() || weights.size() != values.size()) {
      return 0;
    }

    int n = values.size();
    vector<vector<int>> dp(n, vector<int>(capacity + 1));

    for (int i = 0; i < n; i++) {
      dp[i][0] = 0;
    }

    for (int c = 0; c <= capacity; c++) {
      if (weights[0] <= c) {
        dp[0][c] = values[0];
      }
    }

    for (int i = 1; i < n; i++) {
      for (int c = 1; c <= capacity; c++) {
        int case1 = 0, case2 = 0;
        // include the item, if it is not more than the capacity
        if (weights[i] <= c) {
          case1 = values[i] + dp[i - 1][c - weights[i]];
        }
        // exclude the item
        case2 = dp[i - 1][c];
        //  maximum
        dp[i][c] = max(case1, case2);
      }
    }

    return dp[n - 1][capacity];
  }

int main() {
  vector<int> values = {12, 10, 21, 15};
  vector<int> weights = {2, 1, 3, 2};
  int KnapProfit = solveKnapsack(values, weights, 7);
  cout << "Total knapsack profit is " << KnapProfit << endl;
  return 0;
}
