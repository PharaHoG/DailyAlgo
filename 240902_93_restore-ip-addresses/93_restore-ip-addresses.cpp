// 将判断条件整合到一个中
// 如果当前元素无法满足条件，则本层无剩余子树

class Solution {
public:
    vector<string> result;
    string path;
    
    // 将对子树的判断整合到一个函数中
    bool isValid(const string& s, int startIdx, int endIdx) {
        if (startIdx > endIdx)
            return false;
        if (endIdx - startIdx > 2) 
            return false;
        if (s[startIdx] == '0' && startIdx < endIdx)
            return false;
        cout << s.substr(startIdx, endIdx - startIdx + 1) << ' ';
        int num = stoi(s.substr(startIdx, endIdx - startIdx + 1));
        if (num > 255) 
            return false;
        return true;
    }

    void dfs(const string& s, int startIdx, int dotCnt) {
        if (dotCnt == 3) {
            if (isValid(s, startIdx, s.size() - 1)) {
                // 找到一个
                string str = s.substr(startIdx);
                path += str;
                result.push_back(path);
                for (int i = 0; i < str.size(); i++) {
                    path.pop_back();
                }
            }
            return;
        }
        if (dotCnt > 3) return;

        int size = s.size();
        // 本层循环找子树
        for (int i = startIdx; i < size; i++) {
            if (isValid(s, startIdx, i)) {                          // 满足条件时
                // 如果找到了一颗子树
                // 进入，移动 startIdx
                string str = s.substr(startIdx, i - startIdx + 1);
                path += str;
                path.push_back('.');
                dfs(s, i + 1, dotCnt + 1);

                // 回溯
                path.pop_back();
                for (int i = 0; i < str.size(); i++) {
                    path.pop_back();
                }
            } else {
                break;                                              // 不满足条件，则本层无剩余子树，循环结束
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        if (s.size() < 4 || s.size() > 12) return {};
        dfs(s, 0, 0);
        return result;
    }
};

