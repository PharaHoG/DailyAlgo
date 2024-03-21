# 59. 螺旋矩阵II



## 题目描述

给你一个正整数 `n` ，生成一个包含 `1` 到 `n2` 所有元素，且元素按顺时针顺序螺旋排列的 `n x n` 正方形矩阵 `matrix` 。

**示例 1：**

![img](./attachments/spiraln.jpg)

```
输入：n = 3
输出：[[1,2,3],[8,9,4],[7,6,5]]
```

**示例 2：**

```
输入：n = 1
输出：[[1]]
```



## 方法一：



- **思路：**
  - 每次循环包含4个小循环，每个循环画一条边
  - 如果`n`是奇数，需要在最后特判一次画出中间值



**源代码：**

```cpp
vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> result(n, vector<int>(n, 0));
    int cur = 1;
    int row = 0;
    int col = 0;
    int offset = 0;

    for(; n > 2 * offset; offset++) {
        for(int i = 0; i < n - 2*offset - 1; i++) {
            result[row][col++] = cur++;
        }
        // 此时指向的位置还没有被赋值
        // 因此，下一个for循环先赋值，后改变指向位置
        for(int i = 0; i < n - 2*offset - 1; i++) {
            result[row++][col] = cur++;
        }
        for(int i = 0; i < n - 2*offset - 1; i++) {
            result[row][col--] = cur++;
        }
        for(int i = 0; i < n - 2*offset - 1; i++) {
            result[row--][col] = cur++;
        }
        col++;
        row++;
    }

    if (n % 2 == 1) {
        result[n/2][n/2] = n*n;
    }

    return result;
}
```

> 注意点：
>
> 1. 注意边界条件
>    - 每条边画完后，目前指向的位置，还**没有被赋值**
>    - 最后一条边到下一次循环，需要改变当前指向位置

​	