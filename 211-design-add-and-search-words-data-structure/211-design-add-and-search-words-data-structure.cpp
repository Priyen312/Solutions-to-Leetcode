class  Trie {

public:
    Trie *child[26] = {nullptr};
    bool isWord = false;
};
class WordDictionary {
private:
     bool dfs(const string &word, int pos, Trie *root) {
        if (pos == word.size()) return root->isWord;
        if (word[pos] != '.') {
            root = root->child[word[pos] - 'a'];
            return root ? dfs(word, pos + 1, root) : false;
        }
        for (auto i = 0; i < 26; ++i)
            if (root->child[i] && dfs(word, pos + 1, root->child[i]))
                return true;
        return false;
    }
public:
    Trie *root = new Trie();
    WordDictionary() {
        
    }
    
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
    
    bool search(string word) {
        
        return dfs(word, 0, root);
        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */