class Solution {
public:
    string minWindow(string s, string t) {
        
//         if(t == "")
//             return "";
//         unordered_map<char, int> countT, window;
//         int n = s.size();
//         for(auto c: t)
//         {
//             countT[c]++;
//         }
        
        
//         int l = 0, r = 0;
        
//         int minimum_window = INT_MAX;
        
//         int have = 0, need = countT.size();
//         int left = -1, right = -1;
//         for(;r < n; r++)
//         {
//             char c = s[r];
            
//             window[c]++;
            
//             if(countT.find(c) != countT.end() and window[c] == countT[c])
//             {
//                 have++;
//             }
            
//             while(have == need)
//             {
//                 if(r - l + 1 <= minimum_window)
//                 {
//                     minimum_window = r - l - 1;
//                     left = l;
//                     right = r;
//                 }
                
//                 window[s[l]]--;
                
//                 if(countT.find(s[l]) != countT.end() and window[s[l]] < countT[s[l]])
//                 {
//                     have--;
//                 }
//                 l++;
                
//             }
            
            
//         }
        
//         if(minimum_window != INT_MAX)
//             return s.substr(left, right - left + 1);
        
//         else
//             return "";
        

        unordered_map<char, int> countT;
        for(auto c: t) 
            countT[c]++;
        
        int need = t.size(), l = 0, r = 0, minimum_window = INT_MAX, start = 0;
        
        while(r < s.size()){
            
            if(countT[s[r++]]-- > 0) 
                need--; //in t
            
            while(need == 0){ //valid
                if(r - l < minimum_window)  
                    minimum_window = r - (start = l);
                if(countT[s[l++]]++==0) 
                    need++;  //make it invalid
            }  
        }
        
        return minimum_window == INT_MAX? "":s.substr(start, minimum_window);
    
    }
    
};