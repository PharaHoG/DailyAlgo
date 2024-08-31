class Solution {
public:
    vector<string> result;
    string path;
    // 注意 char 和 int 之间的转换
    unordered_map<char, string> digitmap =  { { '2', "abc" }, { '3', "def" }, { '4', "ghi" },
                                              { '5', "jkl" }, { '6', "mno" }, { '7', "pqrs" },
                                              { '8', "tuv" }, { '9', "wxyz" } };
    
    void dfs(string& digits, int idx) {
        if (idx == digits.size()) {
            result.push_back(path);
        }
        for (int i = 0; i < digitmap[digits[idx]].size(); i++) {
            path.push_back(digitmap[digits[idx]][i]);
            dfs(digits, idx + 1);
            path.pop_back();
        }
        return;
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        dfs(digits, 0);
        return result;
    }
};