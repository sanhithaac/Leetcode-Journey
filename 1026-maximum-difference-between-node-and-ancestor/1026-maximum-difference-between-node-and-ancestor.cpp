class Solution {
public:
    int ans = 0;

    void dfs(TreeNode* root, int mini, int maxi) {
        if (root == NULL)
            return;

        mini = min(mini, root->val);
        maxi = max(maxi, root->val);

        ans = max(ans, maxi - mini);

        dfs(root->left, mini, maxi);
        dfs(root->right, mini, maxi);
    }

    int maxAncestorDiff(TreeNode* root) {
        dfs(root, root->val, root->val);
        return ans;
    }
};