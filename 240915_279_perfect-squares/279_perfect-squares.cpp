// 方法一 动态规划
// 完全背包

class Solution {
public:
    int numSquares(int n) {
        vector<int> nums(100);
        for (int i = 1; i <= 100; i++) {
            nums[i-1] = i * i;
        }

        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = nums[i]; j <= n; j++) {
                dp[j] = min(dp[j], dp[j-nums[i]] + 1);
            }
        } 

        return dp[n];
    }
};