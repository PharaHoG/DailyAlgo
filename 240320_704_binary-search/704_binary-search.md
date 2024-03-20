# 704. 二分查找



# 题目描述



给定一个 `n` 个元素有序的（升序）整型数组 `nums` 和一个目标值 `target` ，写一个函数搜索 `nums` 中的 `target`，如果目标值存在返回下标，否则返回 `-1`。


**示例 1:**

```
输入: nums = [-1,0,3,5,9,12], target = 9
输出: 4
解释: 9 出现在 nums 中并且下标为 4
```

**示例 2:**

```
输入: nums = [-1,0,3,5,9,12], target = 2
输出: -1
解释: 2 不存在 nums 中因此返回 -1
```

 

# 方法一：左闭右开区间



**源代码：**

```cpp
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
```



# 方法二：左闭右闭区间



**源代码：**

```cpp
int search_2(vector<int>& nums, int target) {
        // 方法二，左闭右闭区间
        vector<int>::size_type lef = 0, rig = nums.size();

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
```

