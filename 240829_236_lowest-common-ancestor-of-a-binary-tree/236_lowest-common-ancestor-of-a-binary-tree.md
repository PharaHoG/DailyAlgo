# 题目名

## 题目描述





## 方法一：



**思路：**

1. 使用递归函数 findNode。递归的返回值是在该节点以及子节点中是否有目标值。
2. 在每个节点的处理中，如果发现当前节点的两个子节点中都有目标值`left && right`，且是第一次找到公共节点 ``isFirst == true`，说明当前节点是公共祖先节点
3. 如果节点本身就是目标节点，则另一个目标如果在其子节点中，那么这个节点就是公共祖先节点



**源代码：**

```cpp
class Solution {
public:
    bool isFirst = true;
    TreeNode* ancestor = nullptr;
    bool findNode(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return false;
        bool left = findNode(root->left, p, q);
        bool right = findNode(root->right, p, q);
        // 如果节点本身是祖先节点
        if (root->val == p->val || root->val == q->val) {
            if (left || right) {
                ancestor = root;
                isFirst = false;
            }
            return true;
        }
        // 一个节点的子节点是目标节点时
        if (isFirst && left && right) {
            ancestor = root;
            isFirst = false;
        }

        return left || right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        findNode(root, p, q);
        return ancestor;
    }
};
```



**注意点：**

1. 方法不够简洁，对于祖先的判定，分成了两种情况：公共祖先节点不是目标节点和是目标节点



## 方法二：



**思路：**

1. 只有两种情况
   1. 目标节点自身就是公共祖先节点
      - if root = p || root = q
      - return root
   2. 两个目标节点在公共祖先节点的左右子树
      - if left && right
      - return root

1. 通过递归函数的返回值传递目标节点的值
2. 算法只会返回目标节点p和q的值，或者是 left && right 时，节点的值，并沿树向上传递。



**源代码：**

```cpp
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left == NULL) return right;
        if (right == NULL) return left;
        return root;
    }
};
```



**注意点：**

1. 



