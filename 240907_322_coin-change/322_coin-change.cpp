// 方法一 回溯
// 超时
class Solution {
public:
    int cnt = INT_MAX;
    void dfs(vector<int>& coins, int amount, int curcnt) {
        if (amount == 0) {
            cnt = min(curcnt, cnt);
            return;
        } else if (amount < 0) {
            return;
        }
        for (int i = 0; i < coins.size(); i++) {
            dfs(coins, amount-coins[i], curcnt+1);
        }
    }
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        dfs(coins, amount, 0);
        if (cnt == INT_MAX) return -1;
        return cnt;
    }
};