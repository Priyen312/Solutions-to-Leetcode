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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> v;
        
      stack<TreeNode*> m;
        if(root == nullptr)
            return v;
        
        
        m.push(root);
        int c = 0;
        while(m.size())
        {
            vector<int> n; stack<TreeNode*> s;
           
            int size = m.size();
            
            while(size-->0){
          
         
            TreeNode *t =m.top();
            n.push_back(m.top()->val);
            m.pop();
                
            if(c%2==0){
                
                 if(t->left)
                    s.push(t->left);
               
                if(t->right)
                    s.push(t->right);
               
            }
            else{
                if(t->right)
                    s.push(t->right);
                if(t->left)
                    s.push(t->left);

            }
                
        }
            
                m=s;
                v.push_back(n);
                c++;
            
        
        }
        
        return v;
    }
};