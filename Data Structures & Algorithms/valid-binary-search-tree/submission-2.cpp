class Solution {
public:
    bool solve(TreeNode* root, long long lower, long long upper) {
        if (root == nullptr) {
            return true;
        }

        // The node must be strictly inside the allowed range.
        if (root->val <= lower || root->val >= upper) {
            return false;
        }

        return solve(root->left, lower, root->val) &&
               solve(root->right, root->val, upper);
    }

    bool isValidBST(TreeNode* root) {
        return solve(root, LLONG_MIN, LLONG_MAX);
    }
};