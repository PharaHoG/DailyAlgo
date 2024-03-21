#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int lef = 0, rig = nums.size() - 1;
        vector<int> result(nums.size(), 0);
        int k = nums.size() - 1;

        while(lef <= rig) {
            if(nums[lef] * nums[lef] > nums[rig] * nums[rig]) {
                result[k--] = nums[lef] * nums[lef];
                lef++;
            } else {
                result[k--] = nums[rig] * nums[rig];
                rig--;
            }
        }

        return result;
    }
};

int main() {
    Solution s1;

    vector<int> vi{ 0, 2 };

    vi = s1.sortedSquares(vi);

    for(auto i : vi) {
        cout << i << ' ';
    }
}