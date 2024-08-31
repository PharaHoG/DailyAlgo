// 方法一
// 重点在于如果目标节点的左右子树都不为空时
// 如何在保证二叉搜索树性质的前提下，将左右子树放到正确的位置上

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return root;
        if (root->val == key) {
            // 至少有一个节点是空的，返回另一个节点的指针
            if (root->left == nullptr)
                return root->right;
            if (root->right == nullptr)
                return root->left;
            // 两个节点都是非空节点
            TreeNode* leftNode = root->left;
            TreeNode* rightNode = root->right;
            delete root;
            // 将左子树的右节点移动到右子树的最左子节点上
            // TreeNode* cur = rightNode;
            // while (cur->left) {
            //     cur = cur->left;
            // }
            // cur->left = leftNode;
            // return rightNode;
            
            // 或者将右子树移动到左子树的最右子节点上
            TreeNode* cur = leftNode;
            while (cur->right) {
                cur = cur->right;
            }
            cur->right = rightNode;
            return leftNode;
        }
        if (root->val > key)
            root->left = deleteNode(root->left, key);
        if (root->val < key)
            root->right = deleteNode(root->right, key);
        return root;
    }
};

// 方法二 迭代

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* cur = root;
        TreeNode** ppre = &root;

        while (cur != nullptr) {
            if (cur->val > key) {
                ppre = &(cur->left);
                cur = cur->left;
            } else if (cur->val < key) {
                ppre = &(cur->right);
                cur = cur->right;
            } else {
                // 找到目标值
                if (cur->left == nullptr) {
                    *ppre = cur->right;
                    delete cur;
                }
                else if (cur->right == nullptr) {
                    *ppre = cur->left;
                    delete cur;
                } else {
                    // 删除的目标节点的左右两子树都不为空
                    // 找右子树的最左子节点，将左子树连接到他的左节点
                    TreeNode* targetNode = cur;
                    cur = cur->right;
                    while (cur->left != nullptr) {
                        cur = cur->left;
                    }
                    cur->left = targetNode->left;
                    *ppre = targetNode->right;
                    delete targetNode;
                }
                // 到找到目标节点，完成删除操作后，停止继续查找节点
                break;
            }
        }

        return root;
    }
};