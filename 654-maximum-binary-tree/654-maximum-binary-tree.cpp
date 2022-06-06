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
    
    int get(vector<int> &nums, int l, int r)
    {
        int maximum = INT_MIN;
        int index = l;
        for(int i = l; i<r; i++)
        {
            if(nums[i] > maximum)
            {
                maximum = nums[i];
                index = i;
            }
        }
        
        return index;
    }
    TreeNode *generateTree(vector<int> &nums, int l, int r)
    {
        if(l == r)
            return nullptr;
        
        int index = get(nums, l, r);
        
        TreeNode *root = new TreeNode(nums[index]);
        
        root->left = generateTree(nums, l, index);
        root->right = generateTree(nums, index + 1, r);
        
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        
        return generateTree(nums, 0, nums.size());
        
        
    }
};