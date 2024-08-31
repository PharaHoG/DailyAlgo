class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        stack<TreeNode*> st;
        int maxAmount = 0;
        int curAmount = 0;
        vector<int> result;
        TreeNode* cur = root;
        TreeNode* pre = nullptr;

        // 能够保证 cur 在 中 的部分的顺序为搜索二叉树的中序遍历
        while (!st.empty() || cur != nullptr) {
            // 找到最左下节点
            while (cur != nullptr) {
                st.push(cur);
                cur = cur->left;        // 左
            }
            cur = st.top(); st.pop();   // 中
            if (pre == nullptr) {
                // 如果是第一个元素
                curAmount = 1;
            } else if (pre->val == cur->val) {
                curAmount++;
            } else {
                curAmount = 1;
            }
            // 判断是否是众数，或者是新的众数
            if (curAmount == maxAmount) {
                result.push_back(cur->val);
            } else if (curAmount > maxAmount) {
                result.clear();
                result.push_back(cur->val);
                maxAmount = curAmount;
            }
            // cur将移动到下一个
            // 让pre等于当前的cur
            pre = cur;
            cur = cur->right;           // 右
        }

        return result;
    }
};