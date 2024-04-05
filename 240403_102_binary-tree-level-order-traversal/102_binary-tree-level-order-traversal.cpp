#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr)
            return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> result;

        // 只要队列中仍有节点 就还未遍历完
        // 循环就不会结束
        while(!q.empty()) {
            int size = q.size();
            vector<int> level;

            // 对队列中本层的所有节点进行一次遍历
            // 将其子节点加入到队列中
            // 每一次for循环结束，队列中剩余的节点为本层的所有节点
            for(int i = 0; i < size; i++) {
                TreeNode* tmp = q.front();
                level.push_back(tmp->val);
                q.pop();
                if(tmp->left != nullptr)
                    q.push(tmp->left);
                if(tmp->right != nullptr)
                    q.push(tmp->right);
            }
            
            result.push_back(level);
        }

        return result;
    }
};/**
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr)
            return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> result;

        // 只要队列中仍有节点 就还未遍历完
        // 循环就不会结束
        while(!q.empty()) {
            int size = q.size();
            vector<int> level;

            // 对队列中本层的所有节点进行一次遍历
            // 将其子节点加入到队列中
            // 每一次for循环结束，队列中剩余的节点为本层的所有节点
            for(int i = 0; i < size; i++) {
                TreeNode* tmp = q.front();
                level.push_back(tmp->val);
                q.pop();
                if(tmp->left != nullptr)
                    q.push(tmp->left);
                if(tmp->right != nullptr)
                    q.push(tmp->right);
            }
            
            result.push_back(level);
        }

        return result;
    }
};