class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        // 一个摆动序列一定是另一个摆动序列的子序列
        // 贪心
        // 遍历整个数组，找到正差时，找下一个负差
        int cnt;
        int size = nums.size();
        bool lastIsPositive = 0;
        bool isFirst = 1;
        for (int i = 0; i < size; i++) {
            if (i == 0) {
                cnt = 1;
            } else if (nums[i] - nums[i - 1] > 0) {
                if (!lastIsPositive || isFirst) {
                    cnt++;
                    isFirst = false;
                }
                lastIsPositive = true;
            } else if (nums[i] - nums[i - 1] < 0) {
                if (lastIsPositive || isFirst) {
                    cnt++;
                    isFirst = false;
                }
                lastIsPositive = false;
            }
        }

        return cnt;
    }
};