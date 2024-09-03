class Solution {
public:
    vector<string> path;
    vector<vector<string>> result;

    bool isValid(int col) {
        // 检查当前行中 i 位置是否合法
        // 当前检查元素的位置为 { path.size(), idx }
        int row = path.size();
        if (!path.empty()) {
            for (int i = 0; i < row; i++) {
                int j = path[i].find('Q');
                if (col == j) return false;
                if (i + j == row + col) return false;
                if (i - j == row - col) return false;
            }
        }
        return true;
    }

    void dfs(int n) {
        if (path.size() == n) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!isValid(i)) {
                continue;
            }

            string tmp;
            for (int k = 0; k < n; k++) {
                if (k == i) {
                    tmp.push_back('Q');
                } else {
                    tmp.push_back('.');
                }
            }

            path.push_back(tmp);
            dfs(n);
            path.pop_back();
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        if (n > 1 && n < 4) return {};
        dfs(n);
        return result;
    }
};