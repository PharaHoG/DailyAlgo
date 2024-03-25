class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> result;

        for(int cur = 0; cur < nums.size(); cur++) {
            auto it = result.find(target - nums[cur]);
            if(it != result.end()) {
                return {it->second, cur};
            } else {
                result.insert({nums[cur], cur});
            }
        }

        return {};
    }
};