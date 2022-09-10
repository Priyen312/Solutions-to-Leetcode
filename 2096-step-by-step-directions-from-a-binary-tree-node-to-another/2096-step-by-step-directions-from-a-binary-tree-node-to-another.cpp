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
    bool traverse(TreeNode* root, string &path, int dest) {
        if(root->val == dest)
            return true;
        
        if(root->left and traverse(root->left, path, dest))
        {
            path.push_back('L');
            return true;
        }
        else if(root->right and traverse(root->right, path, dest))
        {
            path.push_back('R');
            return true;
        }
        
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string root_to_s, root_to_d;
        
        traverse(root, root_to_s, startValue);
        traverse(root, root_to_d, destValue);
        
        
        while(root_to_s.size() and root_to_d.size() and root_to_s.back() == root_to_d.back())
        {
            root_to_s.pop_back();
            root_to_d.pop_back();
        }
        
        for(auto &c : root_to_s)
            c = 'U';
        
        reverse(root_to_d.begin(), root_to_d.end());
        
        return (root_to_s + root_to_d);
    }
};