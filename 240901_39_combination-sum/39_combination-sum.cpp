class Solution {
public:
    vector<int> path;
    vector<vector<int>> result;
    
    void dfs(vector<int>& candidates,int startIdx, int target) {
        // 无需判断 startIdx 是否等于 size
        // 如果等于，不会进入循环
        if (target < 0) {
            return;
        } else if (target == 0) {
            result.push_back(path);
        }
        int size = candidates.size();
        for (int i = startIdx; i < size; i++) {
            path.push_back(candidates[i]);
            dfs(candidates, i, target - candidates[i]);
            path.pop_back();
        }

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, 0, target);    
        return result;
    }
};