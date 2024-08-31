class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void dfs(int startIdx, int k, int target) {
        if (k == 0 && target == 0) {
            result.push_back(path);
        }
        if (k == 0) return;
        for (int i = startIdx; i <= 9; i++) {
            path.push_back(i);
            dfs(i + 1, k - 1, target - i);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(1, k, n);
        return result;
    }
};