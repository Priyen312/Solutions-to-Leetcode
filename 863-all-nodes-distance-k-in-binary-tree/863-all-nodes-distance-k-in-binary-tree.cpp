/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

void dfs(TreeNode* root, map<int, vector<int>> &adj, int p)
{    
    if(root == nullptr)
        return;
    
    adj[root->val].push_back(p);
    if(root->left)
    {
        adj[root->val].push_back(root->left->val);
        dfs(root->left, adj, root->val);

    }
    if(root->right)
    {
        adj[root->val].push_back(root->right->val);
        dfs(root->right, adj, root->val);
    }
    
    
}
vector<int> bfs(map<int,vector<int>> &adj, map<int,int> &visited, int start, int k)
{
    queue<int> q;
    q.push(start);

    visited[start] = 1;
    if(k == 0)
    {
        return {start};
    }
    vector<int> nodes_at_k;
    while(q.size())
    {
        int s = q.size();
        while(s--)
        {
            int i = q.front();
            q.pop();

            for(auto n: adj[i])
            {
                if(visited.find(n) == visited.end())
                {
                    visited[n] = 1;
                    q.push(n);
                }
            }
        }
        k--;
        if(k == 0)
        {
            while(q.size())
            {
                int node = q.front();
                nodes_at_k.push_back(node);
                q.pop();
            }
            break;
            
        }
    }

    return nodes_at_k;
}


   vector<int> distanceK(TreeNode* root, TreeNode* target, int k)
    {
     
        map<int, vector<int>> adj;
        dfs(root, adj, -1);

        map<int,int> visited;
        visited[-1] = 1;

        return bfs(adj, visited, target->val, k);

   }
};