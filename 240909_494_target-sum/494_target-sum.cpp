#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

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

class Solution2 {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // 将加减问题 转换为 挑几个数使其和为 (sum+target)/2的问题
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > sum) return 0;
        if ((target+sum) & 1) return 0;
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

// 方法三 记忆化回溯
// 一部分用例无法跑出
class Solution {
// 为什么一定需要记忆两个状态（idx和x）
// 仅 idx 相同时，可能对应不同的 x
// 仅 x 相同时，可能对应不同的 idx
public:
    int dfs(vector<int>& nums, int x, int idx, unordered_map<string, int>& memo) {
        if (idx == 0 && nums[idx] == x) {
            if (nums[idx] == 0) return 2;
            return 1;
        }
        if (idx == nums.size()) return false;
        if (x < 0) return false;
        if (x == 0) return 1;
        auto itr = memo.find(to_string(idx) + "-" + to_string(x));
        if (itr != memo.end()) return itr->second;
        auto tmp = memo[to_string(idx) + "-" + to_string(x)] = dfs(nums, x - nums[idx], idx + 1, memo) + dfs(nums, x, idx + 1, memo);
        return tmp;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        // 将加减问题 转换为 挑几个数使其和为 (sum+target)/2的问题
        // 记忆化回溯
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > sum) return 0;
        if ((target+sum) & 1) return 0;
        int x = (target+sum) / 2;
        // memo["idx-x"] idx 到 nums.size()-1 数字，能够组成 x 的组合数
        unordered_map<string, int> memo;

        int result = dfs(nums, x, 0, memo);

        for (auto& p : memo) {
            cout << p.first << ' ' << p.second << ' ';
        }

        return result;
    }
};

int main() {
    Solution2 s2;
    vector<int> nums{ 1, 1, 1, 1, 1 };
    cout << s2.findTargetSumWays(nums, 1);
}