#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxValue(vector<int>& value, vector<int> weight, int n, int w) {
        // dp[i][j] 容量为 j 时，前 i 个物品的最大价值是 dp[i][j]
        // dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i])
        vector<vector<int>> dp(n, vector<int>(w+1, 0));
        for (int j = weight[0]; j <= w; j++) {
            dp[0][j] = value[0];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= w; j++) {
                if (j-weight[i] >= 0) {
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i]);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n-1][w];
    }
};

class Solution2 {
public:
    int maxval = INT_MIN;
    int curval = 0;
    vector<vector<int>> dp;
    int dfs(vector<int>& value, vector<int>& weight, int idx, int n, int w) {
        if (dp[idx][w] != -1) return dp[idx][w];
        dp[idx][w] = maxval = max(curval, maxval);
        if (idx == n) return;
        for (int i = idx; i < n; i++) {
            if (weight[i] <= w) {
                curval += value[i];
                dfs(value, weight, i + 1, n, w-weight[i]);
                curval -= value[i];
            }
        }
    }

    int maxValue(vector<int>& value, vector<int>& weight, int n, int w) {
        dp = vector<vector<int>>(10, vector<int>(100, -1));
        dfs(value, weight, 0, n, w);
        return maxval;
    }
};

int main() {
    Solution2 s1;
    vector<int> value { 15, 20, 30 };
    vector<int> weight { 1, 3, 4 };
    int n = 3;
    int w = 4;

    cout << s1.maxValue(value, weight, n, w);
}