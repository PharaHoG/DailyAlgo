// 将回溯算法的过程看成遍历一棵树
class Solution {
public:

    void dfs(vector<vector<int>>& results, vector<int>& path, int n, int k) {
        if (n < k) return;
        if (k == 0) {
            results.push_back(path);
            return;
        }
        // 一层树的所有情况
        for (int i = 0; i < n; i++) {
            path.push_back(n - i);
            dfs(results, path, n - 1 - i, k - 1);
            path.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> results;
        vector<int> path;
        dfs(results, path, n, k);
        return results;
    }
};