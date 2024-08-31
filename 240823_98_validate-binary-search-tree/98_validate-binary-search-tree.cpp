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

// 方法二 双指针遍历 模版
class Solution {
public:
    TreeNode* pre = nullptr;
    bool helper(TreeNode* cur) {
        if (cur == nullptr) return true;
        bool left = helper(cur->left);
        if (pre != nullptr) {
            if (cur->val <= pre->val)
                return false;
        }
        pre = cur;
        bool right = helper(cur->right);
        return left && right;
    }

    bool isValidBST(TreeNode* root) {
        return helper(root);
    }
};

// 方法三 非递归双指针 模版
// 中序遍历

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* pre = nullptr;

        while (!st.empty() || cur != nullptr) {
            // 左
            // 先找到最左叶子结点
            while (cur != nullptr) {
                st.push(cur);
                cur = cur->left;
            } 
            // 中
            // 找到了，开始处理左叶子结点
            cur = st.top(); st.pop();
            if (pre != nullptr) {
                if (cur->val <= pre->val) {
                    return false;
                }
            }
            pre = cur;
            // 遍历右节点
            cur = cur->right;
        }
        return true;
    }
};