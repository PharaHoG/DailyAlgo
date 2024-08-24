# 题目名 二叉树的中序遍历

## 题目描述

返回中序遍历



## 方法一：迭代法（重点掌握）



**思路：**

1. 使用一个**栈**暂存所有需要处理的节点，栈顶是下一个需要处理的节点
1. 使用一个指针指向下一个需要加入到栈中的节点
1. 栈顶元素没有左子节点的情况下，将此值加入到结果数组，并从栈中弹出，并将其右节点加入到栈中



1. 对于每一棵树，都需要先处理左子节点，然后是父节点，最后是右子节点
2. 每个节点都要当做是一棵树：先处理左子节点，然后是父节点，最后是右子节点



**源代码：**

```cpp
vector<int> inorderTraversal(TreeNode* root) {
        // 迭代法中序遍历
        if (root == nullptr) return {};
        
        stack<TreeNode*> st;
        vector<int> result;

        TreeNode* cur = root;

        while (cur != nullptr || !st.empty()) { // 栈为空时，如果cur不为空指针，说明还有节点需要加入到栈中
            // 处理左子节点
            if (cur != nullptr) {
                st.push(cur);
                cur = cur->left;
            } else {
                // 没有左子节点了，处理父节点，然后将右节点加入栈中
                cur = st.top(); st.pop();
                result.push_back(cur->val);
                cur = cur->right;
            }
        }

        return result;  
    }
```



**注意点：**

1. 



## 方法二：



**思路：**

1. 



**源代码：**

```cpp

```



**注意点：**

1. 



