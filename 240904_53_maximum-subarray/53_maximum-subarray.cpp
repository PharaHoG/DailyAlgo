// 贪心
// 局部最优：一旦连续和为负数，那么一定会减小总和，此时应该从下一位开始算总和
// 整体最优：选取最大的连续和
// 局部最优推出整体最优：局部最优的情况下，一旦找到了最大的连续和，那么就是整体最优

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT_MIN;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (result < sum) {
                result = sum;
            }
            if (sum < 0) {
                sum = 0;
            }
        }
        return result;
    }
};