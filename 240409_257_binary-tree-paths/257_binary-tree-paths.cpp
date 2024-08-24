/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void find_path(TreeNode* cur, vector<TreeNode*>& path, vector<string>& result) {
        // 前序遍历，先处理中间结点
        path.push_back(cur);

        if (cur->left == nullptr && cur->right == nullptr) {
            // 找到一条路径 将当前path中节点加入到result
            string tmp;
            for (int i = 0; i < path.size() - 1; i++) {
                tmp += to_string(path[i]->val);
                tmp += "->";
            }
            tmp += to_string(path.back()->val);

            result.push_back(tmp);
        }
        // 前序遍历
        // 左节点
        if (cur->left != nullptr) {
            find_path(cur->left, path, result);
            path.pop_back();
        }
        if (cur->right != nullptr) {
            find_path(cur->right, path, result);
            path.pop_back();
        }
    }

    vector<string> binaryTreePaths(TreeNode* cur) {
        if (cur == nullptr) return {};

        vector<TreeNode*> path;
        vector<string> result;

        find_path(cur, path, result);

        return result;
    }
};