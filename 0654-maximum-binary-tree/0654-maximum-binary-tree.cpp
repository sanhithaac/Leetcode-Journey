class Solution {
public:
    TreeNode* build(vector<int>& nums, int l, int r) {
        if (l > r) return NULL;

        int idx = l;
        for (int i = l; i <= r; i++) {
            if (nums[i] > nums[idx]) idx = i;
        }

        TreeNode* root = new TreeNode(nums[idx]);
        root->left = build(nums, l, idx - 1);
        root->right = build(nums, idx + 1, r);

        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }
};