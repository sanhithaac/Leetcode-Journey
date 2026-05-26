class Solution {
public:
    vector<TreeNode*> ans;
    unordered_set<int> del;

    TreeNode* solve(TreeNode* root) {
        if(root == NULL) {
            return NULL;
        }

        root->left = solve(root->left);
        root->right = solve(root->right);

        if(del.count(root->val)) {

            if(root->left) {
                ans.push_back(root->left);
            }

            if(root->right) {
                ans.push_back(root->right);
            }

            return NULL;
        }

        return root;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(int x : to_delete) {
            del.insert(x);
        }

        root = solve(root);

        if(root != NULL) {
            ans.push_back(root);
        }

        return ans;
    }
};