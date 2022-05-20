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
    TreeNode* helper(vector<int>& nums,int hi,int lo){
        if(lo>hi) return NULL;
        
        TreeNode *node = new TreeNode(nums[(hi+lo)/2],helper(nums,((hi+lo)/2)-1,lo),helper(nums,hi,((hi+lo)/2)+1));
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums,nums.size()-1,0);
    }
};