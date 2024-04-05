#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;

        // 注意stack中保存的是节点地址
        // 栈顶保存的是下一个要处理的节点地址
        // 根据递归法的设计，反次序压入栈中
        // 即right,left
            // 对root操作，需要将它加入到result数组，并pop掉
            // 对于左右子节点，需要继续遍历
            // 每次遍历先将本节点加入到result数组，如果有左右节点，分别压入栈
            // 直到遇到nullptr

        if (root == nullptr) 
            return result;
        st.push(root);
        while (!st.empty()) {
            TreeNode* cur = st.top();
            st.pop();
            result.push_back(cur->val);
            if (cur->right) 
                st.push(cur->right);
            if (cur->left) 
                st.push(cur->left); 
        }

        return result;
    }
};