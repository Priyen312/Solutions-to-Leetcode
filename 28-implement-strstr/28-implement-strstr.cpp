class Solution {
public:
//     int strStr(string haystack, string needle) {
//         if(haystack.find(needle) != string::npos)
//             return haystack.find(needle);
            
//         return -1;
//     }
    
      int strStr(string haystack, string needle) {
          
          if(needle == "") return 0;
          if(haystack.size() < needle.size()) return -1;
          if(haystack.size() == needle.size() && needle!=haystack) return -1;
           if(haystack == "" and needle != "") return -1;
          
          
          
          int start;
         
          for(int i = 0 ; i<haystack.size() - needle.size() + 1; i++)
          {
              if(haystack[i] == needle[0])
              {         
                  int k = i;
                        int j = 0;
                        start = i;
                  
                      while(haystack[k] == needle[j] && j<needle.size())
                      {
                          k++;j++;
                      }
                  
                  if (j == needle.size() )
                      return start;
                  
                  
                  
              }
          }
          
          return -1;
      }
};