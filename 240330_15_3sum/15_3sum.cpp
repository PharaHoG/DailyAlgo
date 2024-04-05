class Solution {
public: 
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 对vector排序
        // 使用i指针定位一个数字
        // 使用left和right定位另外两个数字
        // 如果三个指针的和小于
        int size = nums.size();
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());
        for(int i = 0; nums[i] <= 0 && i < size; i++) {
            int left = i + 1;
            int right = size;

            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == 0) {
                    // 将当前三元组插入到结果数组中
                    vector<int> tmp{nums[i], nums[left], nums[right]};
                    result.push_back(tmp);
                    // 同时分别移动left和right到下一个不同值
                        // 当前三元组和为0时，如果right值变化，那么left必然变化
                    left++;
                    right--;
                    while(nums[left] == nums[left-1]) {
                        left++;
                    }
                    while(nums[right] == nums[right+1]) {
                        right--;
                    }
                    if(left >= right)
                        break;
                } else if(sum > 0) {
                    right--;
                    while(nums[right+1] == nums[right]) {
                        right--;
                    }
                } else {
                    left++;
                    while(nums[left+1] == nums[left]) {
                        left++;
                    }
                }
            }

            while(i + 1 < size && nums[i] == nums[i+1]) {
                i++;
            }
        }

        return result;
    }
};
