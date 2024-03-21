#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search_1(vector<int>& nums, int target) {
        // 方法一，左闭右开区间
        vector<int>::size_type lef = 0, rig = nums.size();

        while(lef < rig) {
            // 对于左闭右开区间，right索引无意义，因此不能等于left
            vector<int>::size_type mid = (lef + rig) / 2;

            if (target == nums[mid])
                return mid;
            if (target < nums[mid])
                // middle一定不是target，right索引无意义，因此等于middle
                rig = mid;
            else
                // middle一定不是target，left索引有意义，因此等于middle+1
                lef = mid + 1;
        }
        
        return -1;
    }

    int search_2(vector<int>& nums, int target) {
        // 方法二，左闭右闭区间
        vector<int>::size_type lef = 0, rig = nums.size() - 1;

        while(lef < rig) {
            // 对于左闭右闭区间，right索引有意义，因此可以等于left
            vector<int>::size_type mid = (lef + rig) / 2;

            if (target == nums[mid])
                return mid;
            if (target < nums[mid])
                // middle一定不是target，right索引有意义，因此等于middle-1
                rig = mid;
            else
                // middle一定不是target，left索引有意义，因此等于middle+1
                lef = mid + 1;
        }
        
        return -1;
    }

    
};