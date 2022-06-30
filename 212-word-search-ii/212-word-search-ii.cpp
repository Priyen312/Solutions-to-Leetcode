class Trie{
public:
    Trie* child[26] = {nullptr};
    string word;
    bool isWord = false;
        
};



class Solution {
   
public:
    
    Trie* root = new Trie();
    void addWord(string &s)
    {
        Trie* temp = root;
        
        for(auto &c: s)
        {
            int index = c -'a';
            if(temp->child[index] == nullptr){
                temp->child[index] = new Trie();
            }
            temp = temp->child[index];
        }
        temp->word = s;
        temp->isWord = true;
    }
    

    void wordSearch(vector<vector<char>>& board, vector<string> &found_words, Trie *tmp, int r, int c) {
// For single word search in a 2d matrix in WORD SEARCH 1 problem we apply dfs at every point of matrix for that we run 2 for loops and their time complexity is m×n and in each dfs we visit 4^(sizeofword) because we are applying dfs calls to 4 directions for each character of the given word , so the time complexity for that will be m×n×4^(sizeofword).Now coming to this problem, if we dont use Trie we will use the code of word search 1 problem but we will run 1 more for loop for each word in words array , so the time complexity of that would be no_of_word×(m×n×4^(sum_of_lengths_of_all_words)) .Here, we are using trie because of that we dont need to run the extra for loop for each word due to which time complexity drops to m×n×4^(length_of_largest_word) where length_of_largest_word is the height of the trie.
        
            
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