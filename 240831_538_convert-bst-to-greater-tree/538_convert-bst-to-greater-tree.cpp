class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        // 迭代法反向中序遍历（先右后左）
        // 记录当前累加值
        TreeNode* cur = root;
        stack<TreeNode*> st;
        int sum = 0;

        while (!st.empty() || cur) {
            while (cur) {
                st.push(cur);
                cur = cur->right;
            }
            cur = st.top(); st.pop();
            cur->val += sum;
            sum = cur->val;
            cur = cur->left;
        }

        return root;
    }
};

class Solution {
public:
    TreeNode* pre = nullptr;
    void helper(TreeNode* cur) {
        if (cur == nullptr) return;
        // 右
        helper(cur->right);
        // 中
        // 中间节点的处理顺序永远是按元素有序的
        if (pre) {
            // 非首个元素
            cur->val += pre->val;
        }
        pre = cur;
        // 左
        helper(cur->left);
    }

    TreeNode* convertBST(TreeNode* root) {
        helper(root);
        return root;
    }
};

