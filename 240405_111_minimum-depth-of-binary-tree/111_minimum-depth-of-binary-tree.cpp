#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 递归法
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }
        if (root->left != nullptr && root->right == nullptr) {
            return minDepth(root->left) + 1;
        }
        if (root->left == nullptr && root->right != nullptr) {
            return minDepth(root->right) + 1;
        }

        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};

// 迭代法
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;

        while (!q.empty()) {
            int size = q.size();
            depth++;
            for (int i = 0; i < size; i++) {
                TreeNode* tmp = q.front();
                q.pop();
                if (tmp->left == nullptr && tmp->right == nullptr) {
                    return depth;
                }
                if (tmp->right != nullptr) {
                    q.push(tmp->right);
                }
                if (tmp->left != nullptr) {
                    q.push(tmp->left);
                }
            }

        }
        return -1;
    }
};

