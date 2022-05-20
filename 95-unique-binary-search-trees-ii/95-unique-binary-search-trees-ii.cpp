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
    vector<TreeNode*> dfs(int start, int end)
    {
        if(start > end)
            return {nullptr};
        
        vector<TreeNode*> roots;
        for(int i = start; i<=end; i++)
        {
            auto left = dfs(start, i - 1);
            auto right = dfs(i + 1, end);
            
            for(auto l : left)
            {
                for(auto r: right)
                {
                    TreeNode* curr = new TreeNode(i);
                    curr->left = l;
                    curr->right = r;
                    
                    roots.push_back(curr);
                }
                
                
            }
        }
        
        return roots;
    }
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0)
            return {};
        return dfs(1, n);
    }
};