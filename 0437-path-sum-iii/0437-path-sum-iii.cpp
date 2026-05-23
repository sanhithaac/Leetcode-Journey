class Solution {
public:
    int count = 0;

    void solve(TreeNode* root, long long targetSum) {
        if (root == NULL)
            return;

        if (root->val == targetSum)
            count++;

        solve(root->left, targetSum - root->val);
        solve(root->right, targetSum - root->val);
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (root == NULL)
            return 0;

        solve(root, targetSum);

        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);

        return count;
    }
};