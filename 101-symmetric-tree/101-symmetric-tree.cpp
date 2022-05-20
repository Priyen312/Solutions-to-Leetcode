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
    bool b(TreeNode* left,TreeNode* right)
 {
     if(!left && right) return false;
     if(left && !right) return false;
     if(!left && !right) return true;
     if(left->val != right->val)
     {
         return false;
     }
     return b(left->left,right->right) && b(left->right,right->left);


 }
bool isSymmetric(TreeNode* A) {
    if(!A) return 0;
return b(A->left,A->right);

}
};