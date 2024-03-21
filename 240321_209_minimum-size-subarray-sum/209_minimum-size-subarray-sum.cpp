#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int fast = 0, slow = 0;
        int result = 100001;
        int sum = 0;

        while(fast < nums.size()) {
            sum += nums[fast++];

            while(sum >= target) {
                result = result < fast - slow ? result : fast - slow;
                sum -= nums[slow++];
            }
        }

        return result == 100001 ? 0 : result;
    }
};