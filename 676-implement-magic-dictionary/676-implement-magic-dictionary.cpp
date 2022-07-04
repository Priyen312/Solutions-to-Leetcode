class Trie {
public:
    Trie* child[26] = {nullptr};
    bool isWord = false;
};
class MagicDictionary {
private:
    void addWord(string word) {
        Trie *curr = root;
        
        for(auto &c: word)
        {
            if(curr->child[c - 'a'] == nullptr)// if the character isn't on the trie
            {
                curr->child[c - 'a'] = new Trie();// create one
            }
            curr = curr->child[c - 'a'];
        }
        
        curr->isWord = true;
        
    }
    
    bool search(string temp, int &n)
    {
        Trie *curr = root;
        
        for(int i = 0; i < n; i++)
        {
            if(curr->child[temp[i] - 'a'] == nullptr)
                return false;
            
            curr = curr->child[temp[i] - 'a'];
        }
        
        return curr->isWord;
    }
public:
    Trie* root;
    MagicDictionary() {
        root = new Trie();
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto word: dictionary)
        {
            addWord(word);
        }
    }
    
    bool search(string searchWord) {
        
        int n = searchWord.size();
        string temp = searchWord;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < 26; j++)
            {
                //temp = searchWord;
                if(searchWord[i] == 'a' + j )
                    continue;
                temp[i] = 'a' + j;
                if(search(temp, n))
                    return true;
            }
            temp[i] = searchWord[i];
                
        }
        
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */