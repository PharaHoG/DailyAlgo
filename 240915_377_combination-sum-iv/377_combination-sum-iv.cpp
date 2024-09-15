// 动态规划
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target+1, 0);
        sort(nums.begin(), nums.end());

        dp[0] = 1;
        for (int j = 1; j <= target; j++) {
            for (int i = 0; i < nums.size(); i++) {
                if (j >= nums[i]) {
                    dp[j] += dp[j-nums[i]];
                } else {
                    break;
                }
            }
        }

        return dp[target];
    }
};

// 记忆化回溯
class Solution {
public:
    unordered_map<int, int> map;
    int dfs(vector<int>& nums, int target) {
        if (target == 0) {
            return 1;
        }
        if (target < 0) return 0;
        if (map.find(target) != map.end()) {
            return map[target];
        }
        int amt = 0;
        for (int i = 0; i < nums.size(); i++) {
            amt += dfs(nums, target-nums[i]);
        }
        map[target] = amt;
        return map[target];
    }

    int combinationSum4(vector<int>& nums, int target) {
        return dfs(nums, target);
    }
};

// 暴力回溯 超时

class Solution {
public:
    int amt = 0;
    void dfs(vector<int>& nums, int target) {
        if (target == 0) {
            amt++;
        }
        if (target < 0) return;

        for (int i = 0; i < nums.size(); i++) {
            dfs(nums, target-nums[i]);
        }
    }

    int combinationSum4(vector<int>& nums, int target) {
        dfs(nums, target);
        return amt;
    }
};