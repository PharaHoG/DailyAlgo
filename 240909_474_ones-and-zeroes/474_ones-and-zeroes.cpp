// 方法一
// 一维数组 动态规划
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> strns(strs.size());
        for (int i = 0; i < strs.size(); i++) {
            strns[i].first = count(strs[i].begin(), strs[i].end(), '0');
            strns[i].second = count(strs[i].begin(), strs[i].end(), '1');
        } 

        // dp[m][n] 最大值为 m 个 0 和 n 个 1 时，前 i 个 pair 最多可选数
        vector<vector<int>> dp(m+1, vector(n+1, 0));

        for (int i = 0; i < strns.size(); i++) {
            for (int j = m; j >= 0; j--) {
                // 如果大于，说明此格的前置格不在范围内，因此不对此格更新
                if (j >= strns[i].first) {
                    for (int k = n; k >= 0; k--) {
                        if (k >= strns[i].second) {
                            dp[j][k] = max(dp[j-strns[i].first][k-strns[i].second] + 1, dp[j][k]);
                        }
                    }
                }
            }
        }

        return dp[m][n];
    }
};