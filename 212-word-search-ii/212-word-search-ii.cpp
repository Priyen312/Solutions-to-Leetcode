class Trie{
public:
    Trie* child[26] = {nullptr};
    string word;
    bool isWord = false;
        
};



class Solution {
private:
    

    Trie* root=nullptr;
    
    void addWord(string &s)
    {
        Trie* temp = root;
        
        for(auto &c: s)
        {
            int index = c -'a';
            if(temp->child[index] == nullptr){
                temp->child[index]=new Trie;
            }
            temp=temp->child[index];
        }
        temp->word=s;
        temp->isWord = true;
    }
    

    void wordSearch(vector<vector<char>>& board, vector<string> &found_words, Trie *tmp, int r, int c) {
            
        
            
        int n = board.size();
        int m = board[0].size();
            
        
        if(r < 0 || c < 0 || r >= n || c >= m || board[r][c] == '*' || !(tmp->child[board[r][c] - 'a'])) 
        {
            return;
        }
        
        tmp = tmp->child[board[r][c] - 'a'];
        
        
        if(tmp->isWord == true)
        {
            found_words.push_back(tmp->word);
            tmp->isWord = false; // so that the current word is not checked again
        }
        
        char curr_c = board[r][c];
        board[r][c] = '*';
        
            wordSearch(board, found_words, tmp, r + 1, c);
                    wordSearch(board, found_words, tmp, r - 1, c);
                            wordSearch(board, found_words, tmp, r, c - 1);
                                    wordSearch(board, found_words, tmp, r, c + 1);
        

            
        board[r][c] = curr_c;
        
        return;

    }
    
public:
    Solution()
    {
        root = new Trie;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
    
        int n = board.size();
        int m = board[0].size();
        
        vector<string> found_words;
        Trie *node = root;
        for(auto i: words)
        {
            addWord(i);
        }
        
        for(int r = 0; r < n; r++)
        {
            for(int c = 0; c < m; c++)
            {
                wordSearch(board, found_words, node, r, c);
            }
        }
        
     
        return found_words;

    }
};