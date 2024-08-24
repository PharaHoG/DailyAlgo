/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// 回溯法
class Solution {
public:
    vector<TreeNode*> path;
    int tsum = 0;

    bool helper(TreeNode* root) {
        path.push_back(root);
        bool left = false;
        bool right = false;
        if (root->left == nullptr && root->right == nullptr) {
            // 找到一条路径
            int size = path.size();
            int sum = 0;
            for (int i = 0; i < size; i++) {
                sum += path[i]->val;
            }
            if (sum == tsum) {
                return true;
            } else {
                return false;
            }
        }
        // 对于每次递归，期望的意思是，这个根节点的左子树 或 右子树是否有符合条件的路径
        if (root->left != nullptr) {
            left = helper(root->left);
            path.pop_back();
        }
        if (root->right != nullptr) {
            right = helper(root->right);
            path.pop_back();
        }
        // 当只确定了左子树或右子树为true或false时不应该直接返回
        // 而是取 或
        return left || right;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return false;
        }
        tsum = targetSum;
        return helper(root);
    }
};

// 方法二

class Solution2 {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        if (root->left == nullptr && root->right == nullptr && targetSum == root->val) {
            return true;
        }
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};