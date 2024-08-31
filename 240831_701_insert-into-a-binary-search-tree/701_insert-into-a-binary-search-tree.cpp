class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode** pcur = &root;
        while (*pcur != nullptr) {
            if ((*pcur)->val > val)
                pcur = &((*pcur)->left);
            else
                pcur = &((*pcur)->right);
        }
        *pcur = new TreeNode(val);

        return root;
    }
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr)
            root =  new TreeNode(val);
        if (root->val > val) 
            root->left = insertIntoBST(root->left, val);
        if (root->val < val)
            root->right = insertIntoBST(root->right, val);
        return root;
    }
};