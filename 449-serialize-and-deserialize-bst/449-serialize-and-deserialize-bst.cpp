/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    void serializeBST(ostringstream &s, TreeNode* root)
    {
        if(root == nullptr)
            s << "# ";
        
        else
        {
            s << to_string(root->val) << ' ';
            
            serializeBST(s, root->left);
            serializeBST(s, root->right);
        }
        
        
    }
    TreeNode* deserializeBST(istringstream &s)
    {
        string val;
        s >> val;
        if(val == "#")
            return nullptr;
        
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserializeBST(s);
        root->right = deserializeBST(s);
        
        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serializeBST(out, root);
        
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        istringstream in(data);
        return deserializeBST(in);
        
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;