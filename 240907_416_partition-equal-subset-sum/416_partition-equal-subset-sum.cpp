#include <iostream>
#include <unordered_map>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace chrono;

// 方法一
// 回溯 超时

class Solution1 {
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

// 方法三
// 一维数组动态规划

class Solution3 {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto n : nums) {
            sum += n;
        }
        // 如果总和为奇数，无法分割成两个子集
        if (sum % 2 != 0) return false;
        int target = sum/2;

        // dp[j] 表示前 i 个数字能是否能组成 j
        vector<bool> dp(target+1, false);
        dp[0] = true;
        
        for (int i = 0; i < nums.size(); i++) {
            for (int j = target; j >= nums[i]; j--) {
                dp[j] = dp[j] || dp[j-nums[i]];
                if (dp[target]) return true;
            }
        }

        return dp[target];
    }
};

// 方法三 一个用例未通过
// 记忆化回溯

class Solution4 {
public:
    // 能否挑出来k个数等于target
    // 剪枝
    bool partition(vector<int>& nums, int p, int target, unordered_map<int, bool>& memo)
    {
        if(target == 0) return true;

        if(target < 0)  return false;

        if(p == nums.size())    return false;

        if(memo.find(target) != memo.end()) return memo[target];

        // 当前元素挑或不挑
        memo[target] = partition(nums, p+1, target - nums[p], memo) || partition(nums, p+1, target, memo);
        
        return memo[target];
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        unordered_map<int, bool> memo;
        sort(nums.begin(), nums.end());
        for(int n : nums)   sum += n;
        if(sum % 2) return false;
        return partition(nums, 0, sum / 2, memo);
    }
};


int main() {
    vector<int> nums(100, 20);  // 初始化包含300个100的向量

    // Solution1 s1;
    Solution2 s2;
    Solution3 s3;
    Solution4 s4;

    auto start = high_resolution_clock::now();
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    
    // auto start = high_resolution_clock::now();
    // // 调用需要测量的函数
    // s1.canPartition(nums);
    // // 获取结束时间
    // auto end = high_resolution_clock::now();
    // // 计算时间差，单位是微秒
    // auto duration = duration_cast<microseconds>(end - start);
    // cout << "s1 cost " << duration.count() << "us" << '\n';

     start = high_resolution_clock::now();
    // 调用需要测量的函数
    s2.canPartition(nums);
    // 获取结束时间
     end = high_resolution_clock::now();
    // 计算时间差，单位是微秒
     duration = duration_cast<microseconds>(end - start);
    cout << "s2 cost " << duration.count() << "us" << '\n';

     start = high_resolution_clock::now();
    // 调用需要测量的函数
    s3.canPartition(nums);
    // 获取结束时间
     end = high_resolution_clock::now();
    // 计算时间差，单位是微秒
     duration = duration_cast<microseconds>(end - start);
    cout << "s3 cost " << duration.count() << "us" << '\n';

     start = high_resolution_clock::now();
    // 调用需要测量的函数
    s4.canPartition(nums);
    // 获取结束时间
     end = high_resolution_clock::now();
    // 计算时间差，单位是微秒
     duration = duration_cast<microseconds>(end - start);
    cout << "s4 cost " << duration.count() << "us" << '\n';

    return 0;
}