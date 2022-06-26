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
    vector<int> v;
    int maxsum = INT_MIN;
    int maxPathSum(TreeNode* root) {
        
      
        int h = helper(root);
        return maxsum;
    }
    
    int helper(TreeNode* root)
    {
        if(root == nullptr) return 0;
        
        int ld = max(0, helper(root->left));//because the roots have negative values too
        int rd = max(0, helper(root->right));
        
        
        maxsum = max(maxsum, ld + rd + root->val);
        
    
        
        return max(root->val +ld,root->val+rd);
    }
};