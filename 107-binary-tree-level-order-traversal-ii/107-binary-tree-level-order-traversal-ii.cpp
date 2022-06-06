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
//     vector<vector<int>> levelOrderBottom(TreeNode* root) {
//      vector<vector<int>> ans;
//     queue <TreeNode*> q;
        
//         if(root == nullptr )
//             return ans;
        
//         q.push(root);
        
//         while(q.empty() == false)
//         {vector <int> v;
//             int size = q.size();
          
//          while(size-->0)
//          {
//               TreeNode* top = q.front();v.push_back(top->val);
//             q.pop();
            
             
//              if(top->left !=nullptr)
//              {
                 
//                 q.push(top->left);
//                 }
//             if(top->right !=nullptr)
//             {
//                 q.push(top->right);
//             }
//          }
         
//          ans.push_back(v);
        
             
         
            
            
//         }
//         vector<vector<int>>helper;
//         while(ans.size())
//         {
//             helper.push_back(ans.back());ans.pop_back();
//         }
//         return helper;
//     }
    void l(TreeNode* root, int level, vector<vector<int>> &in)
    {
        if(root==nullptr) return;
        
        if(level >= in.size())
        {
            in.push_back(vector<int> ());
        }
        in[level].push_back(root->val);
        l(root->left,level+1, in);
        
        l(root->right,level+1, in);
        
        
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<vector<int>> in;
        l(root, 0, in);
        reverse(in.begin(), in.end());
        return in;
    }
    
    
};