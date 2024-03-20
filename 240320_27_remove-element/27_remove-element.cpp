#include <iostream>
#include <vector>

using namespace std;

class Solution1 {
public:
    int removeElement(vector<int>& nums, int val) {
        // 暴力解法
        auto size = nums.size();

        for (int i = 0; i < size; i++) {
            if(nums[i] == val) {
                for (int j = i + 1; j < size; j++) {
                    // 使用j-1而不是j+1，防止越界
                    nums[j-1] = nums[j];
                }
                // 此时索引i所指数值还未被查找
                i--;
                size--;
            }
        }
        return size;
    }
};


class Solution2 {
public:
    int removeElement(vector<int>& nums, int val) {
        // 左右指针
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right) {
            if(nums[left] == val) {
                nums[left] = nums[right];
                right--;
            } else {
                left++;
            }
        }
        
        return left;
    }
};

class Solution2 {
public:
    int removeElement(vector<int>& nums, int val) {
        // 左右指针
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right) {
            while(left <= right && nums[left] != val) {
                left++;
            }
            while(right >= left && nums[right] == val) {
                right--;
            }
            if(left < right) {
                nums[left++] = nums[right--]; 
            }
        }

        return left;
    }
};

class Solution3 {
public:
    int removeElement(vector<int>& nums, int val) {
        // 快慢指针
        int fast = 0, slow = 0;

        while(fast < nums.size() - 1) {
            if(nums[fast] != val) {
                nums[slow] = nums[fast];
                slow++; 
            }
            fast++;
        }

        return fast - slow;
    }
};

int main() {
    vector<int> v1{ 0,1,2,2,3,0,4,2 };

    Solution2 s;

    s.removeElement(v1, 2);

    for(auto i : v1) {
        cout << i << ' ';
    }

    return 0;
}