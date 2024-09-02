// 题目所给数组中包含重复的元素
// 如果解空间树的每一层中，没有跳过重复的元素，那么在解集中会出现重复的解

class Solution {
public:
    vector<int> path;
    vector<vector<int>> result;
    void dfs(vector<int>& candidates, int startIdx, int target) {
        if (target == 0) {
            result.push_back(path);
        }

        int size = candidates.size();
        for (int i = startIdx; i < candidates.size();; i++) {
            // 跳过重复元素避免重复解
            if (i > startIdx && candidates[i] == candidates[i - 1])
                continue; 
            if (candidates[i] > target)
                break;
            path.push_back(candidates[i]);
            dfs(candidates, i + 1, target - candidates[i]);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target);
        return result;
    }
};