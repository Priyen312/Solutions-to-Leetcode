/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       //
      return helper(root,p,q);
    
        
        
    }
    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q)
    {
           if(root == NULL) return NULL;
    
   
           TreeNode* left = helper(root->left,p,q);
           TreeNode* right = helper(root->right,p,q);
           if(root == p || root == q)
                return root;




              if (left && right) {
                return root;
            }

            // if `x` and `y` exist in the left subtree
            if (left) {
                return left;
            }

            // if `x` and `y` exist in the right subtree
            if (right) {
                return right;
            }

          return NULL;
            }  


};