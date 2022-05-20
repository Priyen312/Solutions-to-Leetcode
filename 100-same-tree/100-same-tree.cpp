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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<int> stp;
        stack<int> stq;
        
        traverseq(q,stq);
        traversep(p,stp);
        bool b = true;
        if(stq.size()!=stp.size())
            return false;
while(stp.size() && stq.top() == stp.top())
        {
    cout<<stq.top()<<stp.top()<<endl;
            stp.pop();
            stq.pop();
        }
        
        if(stp.size() || stq.size())
            return false;
        
        return true;
    }
    void traversep(TreeNode* p,stack<int> &stp)
          {
        if(p == nullptr)
        { stp.push(NULL);
            return;
        }stp.push(p->val);
        traversep(p->left,stp);traversep(p->right,stp);
    }
    
    void traverseq(TreeNode* q,stack<int> &stq)
    {
        if(q == nullptr)
        { stq.push(NULL);
            return;
        }stq.push(q->val);
        traverseq(q->left,stq);traverseq(q->right,stq);
    }
};