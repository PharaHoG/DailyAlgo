// 迭代法
// 前序遍历的二叉搜索树是一个有序数组
// 每次递归，传入的节点的值应该在一个范围内，
    // 即数组中 left 和 right 值中间
class Solution {
public:
    bool helper(TreeNode* root, long long max, long long min) {
        if (root == nullptr) return true;
        if (root->val <= min || root->val >= max) {
            return false;
        }
        return helper(root->left, root->val, min) && helper(root->right, max, root->val);
    }
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MAX, LONG_MIN);
    }
};