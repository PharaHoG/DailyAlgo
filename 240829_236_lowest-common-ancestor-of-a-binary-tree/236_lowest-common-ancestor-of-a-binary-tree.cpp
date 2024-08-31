// 方法一 原方法 方法不够优雅
// 初次解答时忽略了节点本身也可以是祖先的情况
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

// 方法二

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