class Solution {
public:
    int numTrees(int n) {
        // dp[i] 是 i 个节点能够组成的二叉搜索树大小
        // dp[i] = 左子树可能组合 * 右子树可能组合
        // 0-i 轮流作根节点
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i < n+1; i++) {
            for (int j = 0; j <= i-1; j++) {
                // j 为根节点值
                dp[i] += dp [j] * dp[i-j-1];
            }
        }

        return dp[n];
    }
};