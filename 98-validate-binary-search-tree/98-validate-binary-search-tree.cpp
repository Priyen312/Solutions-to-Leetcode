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
    bool isValidBST(TreeNode* root) {
     
      
        long l = LONG_MIN;
        long h = LONG_MAX;
        return helper(root,l,h);
        
         
    }
    
    bool helper(TreeNode* root,long l,long h)
    {
        if(root == NULL)
        {
            return true;
        }
        if(root->val >= h || root->val <= l) return false;
       
      //   bool left = helper(root->left,l,root->val);
      //   bool right = helper(root->right, root->val, h);
      // if(right && left)
      //     return true;
      //   else
      //   return false;
        
        return helper(root->left,l,root->val)
         & helper(root->right, root->val, h);
            
    }
};