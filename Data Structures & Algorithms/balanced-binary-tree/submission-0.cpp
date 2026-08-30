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
    int getLength(TreeNode* root){
        if(root == NULL) return 0;

        return max(getLength(root->left) , getLength(root->right)) + 1;
    }
    bool solve(TreeNode* root){
        if(root == NULL) return true;

        bool left = solve(root->left);
        bool right = solve(root->right);
        
        int leftLength = getLength(root->left);
        int rightLength = getLength(root->right);

        bool curr = (abs(leftLength - rightLength) <= 1) && left && right;

        return curr;
    }

    bool isBalanced(TreeNode* root) {
        return solve(root);
    }
};
