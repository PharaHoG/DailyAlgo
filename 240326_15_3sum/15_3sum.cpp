// 方法一，跑不出来，尝试使用哈希表
class Solution {
public: 
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_set<int> nums_set(nums.begin(), nums.end());
        int n = nums.size();
        unordered_set<vector<int>, vector_hash> result;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int target = -(nums[i] + nums[j]);
                if (nums_set.count(target) && target != nums[i] && target != nums[j]) {
                    vector<int> triplet = {nums[i], nums[j], target};
                    sort(triplet.begin(), triplet.end());
                    result.insert(triplet);
                }
            }
        }

        return vector<vector<int>>(result.begin(), result.end());
    }
};
