// 方法一
// 复杂度 O(N)
// 从前向后遍历数组，记录并更新当前元素所能达到的最大索引
// 在一跳中，一旦到达了上次跳所能达到的最大索引，而没有抵达终点，则说明需要在此跳中，再选择最大一跳作为下一跳

class Solution {
public:
    int jump(vector<int>& nums) {
        // 每次跳跃更新可达范围
        // 在可达范围内找能跳最远的元素
        if (nums.size() < 2) return 0;
        int steps = 1;
        int maxidx = nums.front();
        int curmaxidx = maxidx;

        for (int i = 1; i < nums.size(); i++) {
            if (curmaxidx >= nums.size() - 1) return steps;
            maxidx = max(maxidx, nums[i] + i);
            if (i == curmaxidx) {
                steps++;
                curmaxidx = maxidx;
            }
        }
        return -1;
    }
};