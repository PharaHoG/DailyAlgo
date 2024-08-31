// 方法一，双指针递归
class Solution {
public:
    int diff = INT_MAX;
    TreeNode* pre = nullptr;

    void traversal(TreeNode* cur) {
        if (cur == nullptr) return;
        traversal(cur->left);
        if (pre != nullptr) {
            diff = min(diff, cur->val - pre->val);
        }
        pre = cur;
        traversal(cur->right);
    }

    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        return diff;
    }
};

// 错误解答
// 为什么？
    // 递归调用顺序 != 中序遍历的顺序
    // 如果 pre 作为参数，子节点获取的 pre 节点 == 父节点的 cur
class Solution {
public:
    int diff = INT_MAX;
    void traversal(TreeNode* cur, TreeNode* pre) {
        if (cur == nullptr) return;
        traversal(cur->left, pre);
        if (pre != nullptr) {
            diff = min(diff, cur->val - pre->val);
        }
        pre = cur;
        traversal(cur->right, pre);
    }

    int getMinimumDifference(TreeNode* root) {
        traversal(root, nullptr);
        return diff;
    }
};