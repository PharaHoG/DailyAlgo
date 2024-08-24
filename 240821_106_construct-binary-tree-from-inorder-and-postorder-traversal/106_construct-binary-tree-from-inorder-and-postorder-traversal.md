# 题目名

106. 从中序与后序遍历序列构造二叉树

## 题目描述

给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， postorder 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。



## 方法一：

```cpp
class Solution {
public:
    int num = 0;
    unordered_map<int, int> map;

    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int left, int right) {
        // 为什么基线条件是 left > right 呢？
        // if (left == right) return new TreeNode(inorder[left]);
        if (left > right) return nullptr;     

        int curval = postorder[postorder.size() - 1 - num];
        int mid = 0;
        mid = map[curval];

        TreeNode* root = new TreeNode(curval);
        num++;
        // 如果基线条件设置为 left == right 时 返回 new TreeNode
        // 那么当 root 只有左节点或只有右节点时，缺少返回 nullptr 的情况
        root->right = helper(inorder, postorder, mid + 1, right);
        root->left = helper(inorder, postorder, left, mid - 1);

        return root;
    }


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++) {
            map[inorder[i]] = i;
        }
        return helper(inorder, postorder, 0, inorder.size() - 1);
    }
};
```cpp

**思路：**

1. 



**源代码：**

```cpp
```



**注意点：**

1. 第一个错误版本中，生成的树中包含空节点的节点只有一种：两个节点都是空节点
忽略了只有一个节点是空节点的情况



## 方法二：



**思路：**

1. 



**源代码：**

```cpp

```



**注意点：**

1. 



