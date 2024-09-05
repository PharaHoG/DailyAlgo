// 贪心算法
// 局部最优：如果明天上涨，则今天买入，下跌，明天买入
// 整体最优：在每个最低点买入，最高点卖出
// 最优子结构：整体最优方法一定包含局部最优方法
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if (size < 2) return 0;
        int profit = 0;

        for (int i = 1; i < size; i++) {
            if (prices[i] - prices[i - 1] > 0) {
                profit += prices[i] - prices[i - 1];
            }
        }

        return profit;
    }
};