// 方法一
// 反向查找路径
// 从最后一个元素开始向前查找，如果某个位置可以跳至当前位置
// 则能够跳至这个位置的也一定能够跳至终点

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() < 2) return true;
        int idx = nums.size() - 1;
        for (int i = idx - 1; i >= 0; i--) {
            if (nums[i] >= idx - i) {
                idx = i;
            }
        }

        if (idx == 0) {
            return true;
        }
        return false;
    }
};

// 方法二
// 正向查找范围
// 每个元素位置上，能够抵达的最大范围是 max(之前能够抵达的最大范围, i + 元素值)
// 如果某个位置上，超过了最大能够抵达的范围，返回 false
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        if (nums.size() < 2) return true;
        
        int maxidx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (maxidx < i) return false;
            maxidx = max(maxidx, i + nums[i]);
        }
        return true;
    }
};