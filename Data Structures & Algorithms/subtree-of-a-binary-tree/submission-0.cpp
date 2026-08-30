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
    bool solve(TreeNode* p , TreeNode* q){

        if((p == NULL && q != NULL) || (q == NULL && p != NULL)) return false;

        if(p == NULL && q == NULL) return true;

        if(p->val != q->val) return false;

        bool left = solve(p->left , q->left);
        bool right = solve(p->right , q->right);

        bool curr = p->val == q->val;

        return left && right && curr;

    }

    bool find(TreeNode* root , TreeNode* subRoot){

        if(root == NULL) return false;

        if(root->val == subRoot->val){
            bool ans = solve(root , subRoot);
            if(ans) return true;
        }

        bool left = find(root->left , subRoot);
        bool right = find(root->right , subRoot);

        return left || right;

    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return find(root , subRoot);
    }
};
