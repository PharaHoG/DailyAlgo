#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 迭代法
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;

        queue<TreeNode*> level;
        stack<TreeNode*> checker;
        level.push(root->left);
        level.push(root->right);

        // 每次检查本层queue的左半部分节点，将值压入stack
        // 检查到对称轴后，每次与栈顶值作比较，如果相等，弹出，如果栈为空或不相等，返回false。将子节点加入到level
        // 检查完所有节点后 返回true
        while(!level.empty()) {
            int size = level.size();
            if (size%2 == 1) return false;
            for (int i = 0; i < size/2; i++) {
                TreeNode* tmp = level.front();
                level.pop();
                checker.push(tmp);
                if (tmp != nullptr) {
                    level.push(tmp->left);
                    level.push(tmp->right);
                }
            }
            for (int i = size/2; i < size; i++) {
                TreeNode* tmp = level.front();
                level.pop();
                // 第一次写错在对stack中nullptr的检查不能直接使用ptr->val
                if (checker.empty()) {
                    return false;
                } 
                if (checker.top() == nullptr && tmp != nullptr) {
                    return false;
                }
                if (checker.top() != nullptr && tmp == nullptr) {
                    return false;
                }
                if (checker.top() == nullptr && tmp == nullptr) {
                    checker.pop();
                } else if (checker.top()->val == tmp->val) {
                    checker.pop();
                } else {
                    return false;
                }
                if (tmp != nullptr) {
                    level.push(tmp->left);
                    level.push(tmp->right);
                }
            }
        }

        return true;
    }
};

// 递归法

class Solution {
public:
    bool compare(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right != nullptr) {
            return false;
        }
        if (left != nullptr && right == nullptr) {
            return false;
        }
        if (left == nullptr && right == nullptr) {
            return true;
        }
        if (left->val == right->val) {
            return compare(left->left, right->right) &&
                   compare(left->right, right->left);
        } else {
            return false;
        }
    }

    bool isSymmetric(TreeNode* root) {
        // 分别从左右子树进行遍历，比较每一次遍历的结点
        if (root == nullptr) {
            return true;
        }

        return compare(root->left, root->right);
    }
};

// 栈，迭代法，优化
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        // 将树中节点成对压入栈中，每次取出两个进行比较
        if (root == nullptr) {
            return true;
        }

        stack<TreeNode*> st;
        st.push(root->left);
        st.push(root->right);
        while (!st.empty()) {
            TreeNode* right = st.top(); st.pop();
            TreeNode* left = st.top(); st.pop();
            if (left == nullptr && right == nullptr) {
                continue;
            }
            if (left == nullptr && right != nullptr) {
                return false;
            }
            if (left != nullptr && right == nullptr) {
                return false;
            }
            if (left->val == right->val) {
                st.push(left->left);
                st.push(right->right);
                st.push(left->right);
                st.push(right->left);
            } else {
                return false;
            }
        }

        return true;
    }
};