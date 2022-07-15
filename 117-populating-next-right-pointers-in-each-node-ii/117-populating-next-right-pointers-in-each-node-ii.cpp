/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {

    public:
    Node* connect(Node* root) {
        Node *curr = root;
        while(curr)
        {
            Node* child = new Node(0);
            Node* temp_child = child;
            
            while(curr)
            {
                if(curr->left)
                {
                    child->next = curr->left;
                    child = child->next;
                }
                if(curr->right)
                {
                    child->next = curr->right;
                    child = child->next;
                }
                
                curr = curr->next;
                
            }
            curr = temp_child->next;
        }
        
        
        return root;
        
    }
//     private:
//     Node* fnext(Node* root) {
//         if (root == NULL) return NULL;
//         if (root->left) return root->left;  
//         if (root->right) return root->right;
//         return root;
//         return fnext(root->next);
//     }
    
//     void helper(Node *root) {
        
//         if (root == NULL) return;
//         if (root->left) {
//             if (root->right) {
//                 root->left->next = root->right;
//             } else {
//                 root->left->next = fnext(root->next);
//             }
//         }
        
//         if (root->right) {
//             root->right->next = fnext(root->next);
//         }
        
//         helper(root->right);
//         helper(root->left);
//     }
    
//     public:
//     Node* connect(Node* root)
//     {
//         helper(root);
//         return root;
//     }
    
    
};