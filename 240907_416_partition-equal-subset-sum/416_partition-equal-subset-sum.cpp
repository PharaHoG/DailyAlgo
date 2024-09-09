// 方法一
// 回溯 超时

class Solution {
public:
    bool dfs(vector<int>& nums, int idx, int sum) {
        if (sum == 0) return true;
        if (sum < 0) return false;
        for (int i = idx; i < nums.size(); i++) {
            if (dfs(nums, i+1, sum-nums[i])) return true;
        }
        return false;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto n : nums) {
            sum += n;
        }
        if (sum % 2 != 0) return false;
        return dfs(nums, 0, sum/2);
    }
};

// 方法二 动态规划
// 耗时较长

class Solution2 {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto n : nums) {
            sum += n;
        }
        // 如果总和为奇数，无法分割成两个子集
        if (sum % 2 != 0) return false;

        // dp[i][j] 表示前 i 个数字能是否能组成 j
        vector<vector<bool>> dp(nums.size(), vector<bool>(sum+1, false));
        for (int i = 0; i < nums.size(); i++) {
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;
        
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 1; j < sum+1; j++) {
                if (j >= nums[i]) {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[nums.size()-1][sum/2];
    }
};


int main() {
    // vector<int> nums(100, 100);  // 初始化包含300个100的向量
    // nums[98] = 99;                   // 将倒数第二个元素设为99
    // nums[99] = 97;               // 添加97到最后
    vector<int> nums{1, 2, 2, 5};

    Solution2 s1;
    cout << s1.canPartition(nums);
    return 0;
}