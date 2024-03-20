# 27. 移除元素



# 题目描述



给你一个数组 `nums` 和一个值 `val`，你需要 **[原地](https://baike.baidu.com/item/原地算法)** 移除所有数值等于 `val` 的元素，并返回移除后数组的新长度。

不要使用额外的数组空间，你必须仅使用 `O(1)` 额外空间并 **[原地 ](https://baike.baidu.com/item/原地算法)修改输入数组**。

元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

**示例 1：**

```
输入：nums = [3,2,2,3], val = 3
输出：2, nums = [2,2]
解释：函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。你不需要考虑数组中超出新长度后面的元素。例如，函数返回的新长度为 2 ，而 nums = [2,2,3,3] 或 nums = [2,2,0,0]，也会被视作正确答案。
```

**示例 2：**

```
输入：nums = [0,1,2,2,3,0,4,2], val = 2
输出：5, nums = [0,1,3,0,4]
解释：函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。注意这五个元素可为任意顺序。你不需要考虑数组中超出新长度后面的元素。
```



# 方法一：暴力解法



- 使用两个循环嵌套
  1. 在数组中查找一个目标值
  2. 找到目标值时，将此目标值以后的所有值向前移一位



## 源代码：

```cpp
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
```

> 注意点：
>
> 1. 当使用`j+1`时，索引会越界，因此使用`j = i+1`以及`nums[j-1]`
> 2. 为什么要`i--`?
>    - 当前外层循环中，索引 i 所指的数值*已经进行过*判断了
>    - 在数值移位后，索引 i 新数值还未进行判断，使用`i--`使新数值在下一次循环时进行判断



# 方法二：双指针（左右指针）



- 使用两个指针
  - `left`指针跟踪当前值
  - `right`指针跟踪当前值应该替换的位置



## **源代码：**

```c++
int removeElement(vector<int>& nums, int val) {
    // 快慢指针
    int left = 0;
    int right = nums.size() - 1;

    while(left <= right) {
        // 每次循环中，只有一个指针移动
        if(nums[left] == val) {
            nums[left] = nums[right];
            right--;
            // right 指针值赋给 left 指针后，left 值可能仍未目标值，因此 left不能移动
        } else {
            left++;
        }
    }

    return left;
}
```

> 注意点：
>
> 1. 每次循环中，只有一个指针移动
> 2. `left`值变化后不能移动，因为新值也可能是目标值



# 方法二：双指针（左右指针）（修正）



## 思想



- 外层循环每次将左指针和右指针放到对应的位置，最后将他们交换

- 注意边界情况以及数组越界



## 源代码



```cpp
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
```

> - 越界情况非常难判断
>   - 方法二效率稍低但是容易写



# 方法三：双指针（快慢指针）（没想到）



## 思想



- 使用两个指针，**创建一个新的数组**覆盖原数组
  - 快指针找新数组的元素
  - 慢指针找新数组中新元素的位置
- 快指针每次循环都前进，但慢指针只有在快指针指向的值不为目标值时才前进
- 慢指针的值即为新数组的大小



## 源代码：

```cpp
int removeElement(vector<int>& nums, int val) {
    // 快慢指针
    int fast = 0, slow = 0;
    while(fast < nums.size()) {
        if(nums[fast] != val) {
            nums[slow] = nums[fast];
            slow++; 
        }
        fast++;
    }
    return slow;
}
```









