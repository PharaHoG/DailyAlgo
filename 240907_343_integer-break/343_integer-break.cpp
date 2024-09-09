class Solution {
public:
    int integerBreak(int n) {
        // dp[n] 是 n 由拆分的整数能获得的最大乘积
        // dp[n] = max(1*dp[n-1], 2*dp[n-2], ..., (n-2)*dp[2], 1*(n-1), 2*(n-2), ..., (n-1)*1)
        vector<int> dp(n+1, 0);
        dp[2] = 1;

        for (int i = 3; i < n+1; i++) {
            for (int j = 1; j <= i-2; j++) {
                dp[i] = max(dp[i], max(j*(i-j), j*dp[i-j]));
            }
        }

        return dp[n];
    }
};