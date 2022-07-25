class Trie {
public:
    Trie* child[26] = {nullptr};
    string Pre = "";
    bool isWord = false;
};

class Solution {
public:
    
    Trie *root = new Trie();
    
    void addWord(string word)
    {
        Trie *temp = root;
        
        for(char c: word) {
            if(temp->child[c - 'a'] == nullptr)
                temp->child[c - 'a'] = new Trie();
            
            temp = temp->child[c - 'a'];
        }
        
        temp->Pre = word;
        temp->isWord = true;
    }
    
    string changePre(string &word)
    {
        Trie *temp = root;
        
        for(char c: word) {
           
            if(temp->isWord) {
                return temp->Pre;
            }
            
            if(temp->child[c - 'a'] == nullptr)
                return word;
            else
                temp = temp->child[c - 'a'];
            
        }
                
        
        return word;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        for(auto word: dictionary) {
            addWord(word);
        }
        
        istringstream s(sentence);
        string word, ans = "";
        
        while(s >> word) {
            ans += changePre(word) + " ";
        }
        
        if(ans != "")
            ans.pop_back();
        
        return ans;
    }
};