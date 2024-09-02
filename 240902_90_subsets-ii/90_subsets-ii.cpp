// 跳过重复元素的方式应该是 continue 而不是 i++;
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void dfs(vector<int>& nums, int startIdx) {
        result.push_back(path);
        int size = nums.size();
        if (startIdx == size) {
            return;
        }
        // 跳过重复元素
        for (int i = startIdx; i < size; i++) {
            if (i > startIdx && nums[i] == nums[i - 1]) {
                // 错误方式 i++
                continue;
            } else {
                path.push_back(nums[i]);
                dfs(nums, i + 1);
                path.pop_back();
            }
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return result;
    }
};
