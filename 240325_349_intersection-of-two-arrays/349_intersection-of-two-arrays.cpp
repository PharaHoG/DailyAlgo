// 常规，使用set或者map
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // 每个在第一个数组中出现的，加入到map中
        unordered_map<int, int> sec;

        for(auto iter = nums1.begin(); iter != nums1.end(); iter++) {
            sec[*iter] = 0;
        }
        for(auto iter = nums2.begin(); iter != nums2.end(); iter++) {
            if(sec.find(*iter) != sec.end()) {
                sec[*iter]++;
            }
        }

        vector<int> result;
        for(auto iter = sec.begin(); iter != sec.end(); iter++) {
            if(iter->second) {
                result.push_back(iter->first);
            }
        }
        return result;
    }
};

// 由于数据 在1~1000，所以可用数组
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        bool hash[1000] = {false};
        unordered_set<int> result_set;

        for(int num : nums1) {
            hash[num] = true;
        }
        for(int num : nums2) {
            if(hash[num])
                result_set.insert(num);
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
};