// 方法一 正确解答
class Solution {
public:
    vector<vector<string>> result;
    vector<string> path;
    int isPalindrome(const string& s, int startIdx, int endIdx) {
        // 判断给定字符串的范围是否为回文串
        // 不检查输入范围是否合法
        while (startIdx < endIdx) {
            if (s[startIdx++] != s[endIdx--]) {
                return false;
            }
        }
        return true;
    }

    void dfs(const string& s, int startIdx) {
        // 找到了一个组合方式
        int size = s.size();
        if (startIdx == size) {
            result.push_back(path);
            return;
        }

        for (int i = startIdx; i < size; i++) {
            // 只有找到了回文串，才将其加入path中
            if (isPalindrome(s, startIdx, i)) {
                string str = s.substr(startIdx, i - startIdx + 1);
                path.push_back(str);
                dfs(s, i + 1);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        dfs(s, 0);
        return result;
    }
};

// 方法一 判断找到回文串的方式错误
class Solution {
public:
    vector<vector<string>> result;
    vector<string> path;
    int isPalindrome(const string& s, int startIdx, int endIdx) {
        // 判断给定字符串的范围是否为回文串
        // 不检查输入范围是否合法
        while (startIdx < endIdx) {
            if (s[startIdx++] != s[endIdx--]) {
                return false;
            }
        }
        return true;
    }

    void dfs(const string& s, int startIdx) {
        // 找到了一个组合方式
        int size = s.size();
        // 忽略了如果字符串本身就是一个回文串
        // 那么将直接返回，不进行递归
        if (isPalindrome(s, startIdx, size - 1)) {
            path.push_back(substr(s, startIdx));
            result.push_back(path);
            path.pop_back();
            return;
        }

        for (int i = startIdx; i < size; i++) {
            // 只有找到了回文串，才将其加入path中
            if (isPalindrome(s, startIdx, i)) {
                string str = s.substr(startIdx, i - startIdx + 1);
                path.push_back(str);
                dfs(s, i + 1);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        dfs(s, 0);
        return result;
    }
};