// 方法一 
// 通过回溯法，找到所有可能的路径
// 解法超时

class Solution {
public:
    vector<string> path;
    vector<vector<string>> result;
    unordered_set<int> usedticketsidx;
    int lastidx;

    void dfs(vector<vector<string>>& tickets, const string& start, int times) {
        if (times == tickets.size()) {
            path.push_back(tickets[lastidx][1]);
            result.push_back(path); 
            path.pop_back();
            return;
        }

        for (int i = 0; i < tickets.size(); i++) {
            if (usedticketsidx.contains(i)) {
                continue;
            } else if (tickets[i][0] != start) {
                continue;
            } else {
                usedticketsidx.insert(i);
                path.push_back(start);
                lastidx = i;
                if (dfs(tickets, tickets[i][1], times + 1)) {
                    return;
                }
                usedticketsidx.erase(i);
                path.pop_back();
            }
        }
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        dfs(tickets, "JFK", 0);
        
        // for (auto &vs : result) {
        //     for (auto &s : vs) {
        //         cout << s << ' ';
        //     }
        //     cout << '\n';
        // }

        // 找到 result 中字典序最小的答案
        if (result.size() == 1)
            return result[0];

        vector<string> minPath = result[0];
        for (int i = 1; i < result.size(); i++) {
            if (result[i] < minPath) {
                minPath = result[i];
            }
        }

        return minPath;
    }
};