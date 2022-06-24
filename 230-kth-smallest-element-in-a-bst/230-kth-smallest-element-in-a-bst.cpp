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
    int c = 0; int ans = 0;
    void v(TreeNode* root,int k)
    {
        if(root == nullptr) return ;
        
        
        v(root->left , k);
        c++;
        if(c == k)
             ans = root->val;
        kthSmallest(root->right, k);
  
    }
    int kthSmallest(TreeNode* root, int k) {
        
     
        
        v(root , k);
        return ans;
        
     
    }
};