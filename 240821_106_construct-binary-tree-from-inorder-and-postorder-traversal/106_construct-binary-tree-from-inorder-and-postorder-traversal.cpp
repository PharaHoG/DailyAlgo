// 解答
class Solution {
public:
    int num = 0;
    unordered_map<int, int> map;

    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int left, int right) {
        // 为什么基线条件是 left > right 呢？
        // if (left == right) return new TreeNode(inorder[left]);
        if (left > right) return nullptr;     

        int curval = postorder[postorder.size() - 1 - num];
        int mid = 0;
        mid = map[curval];

        TreeNode* root = new TreeNode(curval);
        num++;
        root->right = helper(inorder, postorder, mid + 1, right);
        root->left = helper(inorder, postorder, left, mid - 1);

        return root;
    }


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++) {
            map[inorder[i]] = i;
        }
        return helper(inorder, postorder, 0, inorder.size() - 1);
    }
};