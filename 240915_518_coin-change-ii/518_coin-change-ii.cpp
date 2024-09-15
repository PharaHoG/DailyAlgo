// 方法一
// 由于完全背包的递推公式取决于同一行位于左侧，以及上一行同一位置的值，因此只能从小到大遍历amount
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        sort(coins.begin(), coins.end());
        dp[0] = 1;

        for (int i = 0; i < coins.size(); i++) {
            for (int j = 0; j <= amount; j++) {
                if (j >= coins[i]) {
                    dp[j] = dp[j] + dp[j-coins[i]];
                } else {
                    dp[j] = dp[j];
                }
            }
        }

        return dp[amount];
    }
};

// 方法二 优化方法一
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        sort(coins.begin(), coins.end());
        dp[0] = 1;

        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) {
                dp[j] += dp[j-coins[i]];
            }
        }

        return dp[amount];
    }
};

// 错误方法
// 没有考虑重复组合的情况

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        sort(coins.begin(), coins.end());
        
        dp[0] = 1;

        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (i >= coins[j]) {
                    dp[i] += dp[i-coins[j]];
                } else {
                    break;
                }
            }
        }

        return dp[amount];
    }
};