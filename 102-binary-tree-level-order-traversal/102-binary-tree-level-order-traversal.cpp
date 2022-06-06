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
public:map<int,vector<int>> m;
    void l(TreeNode* root, int level, vector<vector<int>> &in)
    {
        if(root==nullptr) return;
        
        if(level == in.size())
        {
            in.push_back(vector<int> ());
        }
        in[level].push_back(root->val);
        l(root->left,level+1, in);
        
        l(root->right,level+1, in);
        
        
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
      
        
        vector<vector<int>> in;
        l(root,0, in);
       // for(auto x:m)
       // {
       //     in.push_back(x.second);
       // }
     return in;
        }
        
    
        
        
};