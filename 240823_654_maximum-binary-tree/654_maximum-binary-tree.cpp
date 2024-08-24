class Solution {
public:
    TreeNode* helper(vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        // 找到 left 和 right 中的最大值以及索引值
        int maxidx = -1;
        int maxval = -1;
        for (int i = left; i <= right; i++) {
            if (nums[i] > maxval) {
                maxval = nums[i];
                maxidx = i;
            }
        }

        // 将最大值作为节点，递归求子节点
        TreeNode* root = new TreeNode(maxval);
        root->left = helper(nums, left, maxidx - 1);
        root->right = helper(nums, maxidx + 1, right);

        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};