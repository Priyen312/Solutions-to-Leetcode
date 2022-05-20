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
    bool isBalanced(TreeNode* root) {
        bool b = true;
        helper(root,b);
        return b;
    }
    
    int helper(TreeNode* root, bool &b)
    {
        if(root == NULL)
            return 0;
      
            int l = helper(root->left,b); int r = helper(root->right,b);
            
            if(!(abs(l-r)<=1))
            {
                b = false;
            }
            return max(l,r) + 1;
       
        
    }
    
};