// 方法一
// 横向层循环去重：排列数组，当前元素与上一个元素相同时跳过
// 纵向深度递归去重：使用 map 记录初始数组中元素数量
    // 使用 map 跟踪当前 path 上此元素剩余可用的次数


class Solution {
public:
    unordered_map<int, int> numscnt;
    vector<int> path;
    vector<vector<int>> result;

    void dfs(vector<int>& nums) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            } else if (numscnt[nums[i]] == 0) {
                continue;
            } 
            // 当前元素可以使用
            numscnt[nums[i]]--;
            path.push_back(nums[i]);
            dfs(nums);
            numscnt[nums[i]]++;
            path.pop_back();
        }
    } 

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (auto& n : nums) {
            numscnt[n]++;
        }
        dfs(nums);

        return result;
    }
};