// 方法一 动态规划

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // dp[n] 总金额为n时，消耗的硬币的最少数量
        vector<unsigned int> dp(amount+1, INT_MAX);
        dp[0] = 0;
        
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (i == coins[j]) {
                    dp[i] = 1;
                    break;
                } else if (i > coins[j]) {
                    // 如果dp[i-nums[j]]的方法数为 0，说明当前面额无法凑成 i
                    if (dp[i - coins[j]] != 0) {
                        dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                    }
                }
            }
        }

        if (dp[amount] == INT_MAX) return -1;
        return dp[amount];
    }
};

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // dp[n] 总金额为n时，消耗的硬币的最少数量
        vector<unsigned int> dp(amount+1, UINT_MAX);
        dp[0] = 0;
        
        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) {
                if (dp[j - coins[i]] != UINT_MAX) {
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                }
            }
        }

        if (dp[amount] == UINT_MAX) return -1;
        return dp[amount];
    }
};