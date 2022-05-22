class Solution {
public:int Lo,maxlen = 0;
  string longestPalindrome(string s) {
    if (s.size() < 1) return "";
      if(s.size() == 1) return s;
    int start = 0, end = 0;
    for (int i = 0; i < s.size(); i++) {
     expandAroundCenter(s, i, i);
     expandAroundCenter(s, i, i + 1);
       
        
    }
    return s.substr(Lo, maxlen);
}

 void expandAroundCenter(string s, int left, int right) {
    int L = left, R = right;
    while (L >= 0 && R < s.size() && s[L] == s[R]) {
        L--;
        R++;
    }
     if(maxlen < R - L - 1)
     {
         Lo = L + 1;
         maxlen = R - L - 1;
     }

}
};