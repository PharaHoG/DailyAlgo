// 与数组中选出 k 个数字组合的区别在于选出的结果中，元素的数量是不一致的
// 可以看做每次挑选某一个元素，或者不挑选元素
// 即直接将当前 path 加入到 result 中

class Solution {
public:
    vector<int> path;
    vector<vector<int>> result;

    void dfs(vector<int>& nums, int startIdx) {
        result.push_back(path);

        int size = nums.size();
        for (int i = startIdx; i < size; i++) {
            path.push_back(nums[i]);
            dfs(nums, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return result;
    }
};