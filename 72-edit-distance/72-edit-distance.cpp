class Solution {
private:
    int recurrsion_solution(string word1, string word2) {
        //O(3^n)
        if (word1.length() == 0) return word2.length();
        if (word2.length() == 0) return word1.length();
        return recurrsion(word1, word2, 0,0);
    }
    
   
    int recurrsion(string word1, string word2, int i, int j)
    {
        if(i == word1.size() and j == word2.size())
            return 0;
        if(i == word1.size())
            return word2.size() - j;
        else if(j == word2.size())
            return word1.size() - i;
        
        if(word1[i] == word2[j])
            return recurrsion(word1, word2, i + 1, j + 1);
        else 
        return 1 + min(recurrsion(word1, word2, i + 1, j + 1),                                               
                        min(recurrsion(word1, word2, i + 1, j),
                                recurrsion(word1, word2, i, j + 1))
                      
                      );
    }
    
    
public:
    int performOperations(string word1, string word2, int i, int j, vector<vector<int>> &memo)
    {
        if(i == word1.size() and j == word2.size())
            return 0;
        if(i == word1.size())
            return word2.size() - j;
        else if(j == word2.size())
            return word1.size() - i;
        if(memo[i][j] != -1)
            return memo[i][j];
        if(word1[i] == word2[j])
            return memo[i][j] = performOperations(word1, word2, i + 1, j + 1, memo);
        else 
        return memo[i][j] = 1 + min(performOperations(word1, word2, i + 1, j + 1, memo),                                               
                        min(performOperations(word1, word2, i + 1, j, memo),
                                performOperations(word1, word2, i, j + 1, memo))
                      
                      );
    }
    
    int minDistance(string word1, string word2) {
        //O(len1 * len2), O(len1 * len2)
        if (word1.length() == 0) return word2.length();
        if (word2.length() == 0) return word1.length();
        
        vector<vector<int>> memo(word1.size() + 1, vector<int> (word2.size() + 1, -1));
        return performOperations(word1, word2, 0, 0, memo);
    }
};