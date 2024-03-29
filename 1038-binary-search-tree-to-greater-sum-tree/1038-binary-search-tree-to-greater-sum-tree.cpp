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
    int cnt = 0;
    void convert(TreeNode* root) {
        
        if(root == nullptr) {
            return;
        }
        
        convert(root->right);
        root->val += cnt;
        
        cnt = root->val;
        convert(root->left);
    }
    TreeNode* bstToGst(TreeNode* root) {
        convert(root);
        return root;
    }
};