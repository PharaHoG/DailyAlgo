class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int result = 0;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* tmp = q.front(); q.pop();
                if (i == 0) result = tmp->val;
                if (tmp->left != nullptr) {
                    q.push(tmp->left);
                }
                if (tmp->right != nullptr) {
                    q.push(tmp->right);
                }
            }
        } 

        return result;
    }
};

// 回溯法
class Solution {
public:
    int max_depth = -1;
    int result = 0;
    void traversal(TreeNode* root, int depth) {
        if (root->left == nullptr && root->right == nullptr) {
            if (depth > max_depth) {
                max_depth = depth;
                result = root->val;
            }
        }
        if (root->left != nullptr) {
            traversal(root->left, ++depth);
            --depth;
        }
        if (root->right != nullptr) {
            traversal(root->right, ++depth);
            --depth;
        }
        return;
    }

    int findBottomLeftValue(TreeNode* root) {
        traversal(root, 0);
        return result;
    }
};