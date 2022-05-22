class Solution {
public:
//     int count(string x, string y)
//     {
//         int i = 0; int j = 0;
        
//         while(i < x.size())
//         {
//             if(x[i] != y[i])
//             {
//                 j++;
//                 if(j > 1)
//                     return 0;
//             }
//             i++;
//         }
        
        
//         return j;
//     }
//     int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
//         queue<string> q;
        
        
//         q.push(beginWord);
//         bool b = false;
//         for(int i = 0; i < wordList.size(); i++)
//         {
//             if(wordList[i] == endWord)
//                 b = true;
//         }
//         set<string> words(wordList.begin(), wordList.end());
        
//         set<string> used;
        
//         if(b)
//         {
//         int level = 0;
//         while(q.size())
//         {
//             level++;
//             int s = q.size();
            
//             while(s--)
//             {
//                 string word = q.front();
//                 q.pop();
//                 if(word == endWord)
//                     return level;
                
//                 for(auto i: words)
//                 {
//                     string new_word = i;
//                     if(!used.count(new_word))
//                     {
//                        if(count(new_word, word) == 1)
//                         {
//                                 q.push(i);
//                                 used.insert(new_word);
//                                 words.erase(i);
//                         }
                        
//                     }
                    
//                 }
                    
                    
                
//             }
                
            
//         }
            
             
        
//     }
        
     
//          return 0;
// }
    
   
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;// create a q for bfs
       
        set<string> st,words;
       
       for(string s:wordList)// create a set for storing the words
            words.insert(s);
        
       st.insert(beginWord);// used words
        
       q.push(beginWord);
        
       int res=0;
        
       while(q.size()){
            int n = q.size();
            res++;
            
           while(n--){
                
               string s = q.front();
                
               if(s==endWord) // if the word is the endWord then return res
                    return res;
                
               q.pop();
                
               string t;
                
               for(int i=0;i<s.size();i++){// traverse the word
                    
                   t=s;
                    
                   for(int j='a';j<='z';j++){// for every character in the alphabet, make the position as that character
                        t[i]=j;
                        if(words.count(t) and !st.count(t)){// if the current formed word is not already used and is in the wordList then push it in the q and use it
                            q.push(t);
                            st.insert(t);
                        }
                    }
                }
            }
        }
        return 0;
    }
};