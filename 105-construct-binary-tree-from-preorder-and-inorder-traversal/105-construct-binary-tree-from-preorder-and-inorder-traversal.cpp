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
public:int i = 0; map<int,int> m;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
      
        for(int i = 0 ; i < inorder.size(); i++)
        {
            m[inorder[i]] = i;
        }
        
       
        return helper(preorder,0,inorder.size()-1);
    }
    
   TreeNode* helper(vector<int>& preorder, int left, int right)
    {
        
        if(left>right) return nullptr;
        int val = preorder[i++];
        TreeNode* root = new TreeNode(val);
        
        root->left = helper(preorder,left,m[val]-1);
        root->right=helper(preorder,m[val]+1,right);
        
        return root;
    }};