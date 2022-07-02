class Trie {
private:
    Trie* child[26] = {nullptr};
    bool isWord = false;
public:
    
    Trie() {
      
    }
    
    void insert(string word) {
        Trie* tmp = this;
        for(char c: word)
        {
            if(tmp->child[c - 'a'] == nullptr)
            {
                tmp->child[c - 'a'] = new Trie();
            }
            
            tmp = tmp->child[c - 'a'];
        }
        
        tmp->isWord = true;
    }
    
    bool search(string word) {
        Trie *tmp = this;
        for(char c: word)
        {
            if(tmp->child[c - 'a'] == nullptr)
                return false;
            tmp = tmp->child[c - 'a'];
        }
        
        return tmp->isWord;
        
    }
    
    bool startsWith(string prefix) {
        Trie *tmp = this;
        for(char c: prefix)
        {
            if(tmp->child[c - 'a'] == nullptr)
                return false;
            tmp = tmp->child[c - 'a'];
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */