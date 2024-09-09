// 方法一
// 动态规划

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // 将加减问题 转换为 挑几个数使其和为 (sum+target)/2的问题
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > sum) return false;
        if ((target+sum) & 1) return false;
        int x = (target+sum) / 2;

        // sum + target = 2*x
        // x 为加数的和
        // dp[i][j] 是前 i 个数字能够组成和 j 的组合数量
        vector<vector<int>> dp(nums.size(), vector<int>(x+1, 0));
        dp[0][0] = 1;
        // 当 nums[0] = 0，dp[0][0] = 2时
        if (nums[0] <= x) dp[0][nums[0]]++;

        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < x+1; j++) {
                if (j >= nums[i]) {
                    dp[i][j] = dp[i-1][j-nums[i]] + dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[nums.size()-1][x];
    }
};

// 方法二
// 一维数组 动态规划

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // 将加减问题 转换为 挑几个数使其和为 (sum+target)/2的问题
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > sum) return false;
        if ((target+sum) & 1) return false;
        int x = (target+sum) / 2;

        // sum + target = 2*x
        // x 为加数的和
        // dp[j] 是前 i 个数字能够组成和 j 的组合数量
        vector<int> dp(x+1, 0);
        if (nums[0] <= x) dp[nums[0]] = 1;
        dp[0]++;

        for (int i = 1; i < nums.size(); i++) {
            for (int j = x; j >= 0; j--) {
                if (j >= nums[i]) {
                    dp[j] = dp[j-nums[i]] + dp[j];
                }
            }
        }

        return dp[x];
    }
};

