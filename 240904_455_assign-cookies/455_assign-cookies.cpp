// 贪心

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int result = 0;
        int gi = 0, si = 0;
        while (gi < g.size() && si < s.size()) {
            if (g[gi] <= s[si]) {
                result++;
                gi++;
            }
            si++;
        }

        return result;
    }
};