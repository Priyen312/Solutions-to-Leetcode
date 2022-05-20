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
    int helper(TreeNode* root)
    {
        if(root==nullptr) return 0;
        
        
        int l = helper(root->left);
        int r = helper(root->right);
        
        int h = min(l,r) + 1;
        return (l==0||r==0)?(l+r+1):h;
    }
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        return helper(root);
    }
};