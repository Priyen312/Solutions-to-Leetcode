/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public: map<Node*, Node*> memo;
   
    Node* cloneGraph(Node* n) {
        if(n == nullptr) return n;
        if(memo.find(n)!= memo.end())
        {
            return memo[n];
           
        }
        
        Node* clone = new Node(n->val);
        memo[n] = clone;
            
            for(auto i: n->neighbors)
            {
               clone->neighbors.push_back(cloneGraph(i));
            }
            
        
        return clone;
    }
};