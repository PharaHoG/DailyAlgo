// 方法一
// 动态规划 形似 416 
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int target = sum/2;

        // dp[j] 表示前 i 个数字能是否能组成 j
        vector<bool> dp(target+1, false);
        dp[0] = true;
        
        for (int i = 0; i < stones.size(); i++) {
            for (int j = target; j >= stones[i]; j--) {
                dp[j] = dp[j] || dp[j-stones[i]];
            }
        }

        int i = 0;
        for (; i <= target; i++) {
            if (dp[target-i]) break;
        }

        if (sum & 1) return 2*i+1;
        return 2*i;
    }
};

// 方法二 错误
// 贪心

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int target = INT_MAX;
        int left = 0, right = stones.size() - 1;
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int sumA = 0;
        int sumB = sum - sumA;
        sort(stones.begin(), stones.end());

        while (left < right) {
            if (abs(sumA - (sumB - (sumA+stones[left]))) <= abs(sumA - (sumB - (sumA+stones[right])))) {
                sumA += stones[left];
                sumB -= stones[left];
                left++;
            } else {
                sumA += stones[right];
                sumB -= stones[right];
                right--;
            }
            target = min(target, abs(sumA-sumB));
        }

        return target;
    }
};