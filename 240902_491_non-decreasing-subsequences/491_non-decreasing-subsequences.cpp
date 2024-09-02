// 方法一
// 忽略了元素相同的情况，只考虑了相邻元素相同的情况
    // 由于题目要求数组的顺序不能改变
    // 因此需要一种方式记录已经使用过的元素
    // 如果遇到重复的元素 跳过
    // 重复是对当前层来说，因此每层需要重置
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void dfs(vector<int>& nums, int startIdx) {
        if (path.size() >= 2) {
            result.push_back(path);
        }

        int size = nums.size();
        
        // 记录使用过的元素的集合必须声明为局部变量
        // 如果声明为全局变量，并在每次递归时调用
        // 那么本层使用过的元素，会在本层 dfs 的下一次递归中 被清除
        unordered_set<int> usedNums;
        for (int i = startIdx; i < size; i++) {
            // 横向 循环遍历层
            if (usedNums.contains(nums[i]))
                continue;
            
            usedNums.insert(nums[i]);
            if (path.empty() || nums[i] >= path.back()) {
                // 纵向 向下一层递归
                path.push_back(nums[i]);
                dfs(nums, i + 1);
                path.pop_back();
            }
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        dfs(nums, 0);
        return result;
    }
};


// 忽略了元素相同的情况，只考虑了相邻元素相同的情况
    // 由于题目要求数组的顺序不能改变
    // 因此需要一种方式记录已经使用过的元素
    // 如果遇到重复的元素 跳过
// 错误解答
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    
    void dfs(vector<int>& nums, int startIdx) {
        if (path.size() >= 2) {
            result.push_back(path);
        }

        int size = nums.size();
        for (int i = startIdx; i < size; i++) {
            // 横向 循环遍历层
            if (i > startIdx && nums[i] == nums[i - 1]) {
                continue;
            } else {
                if (path.empty() || nums[i] >= path.back()) {
                    // 纵向 向下一层递归
                    path.push_back(nums[i]);
                    dfs(nums, i + 1);
                    path.pop_back();
                }
            }
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        dfs(nums, 0);
        return result;
    }
};

