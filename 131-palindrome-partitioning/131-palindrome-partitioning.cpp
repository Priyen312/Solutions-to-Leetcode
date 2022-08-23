class Solution {
public:
    bool ispalin(string &s,int i, int j)
    {
        while(i<j)
        {
            if(s[i++]!=s[j--])
                return false;
        }
        
        return true;
    }
    
    vector<vector <string>> res;
    void dfs(string &s, int st,vector<string> &sub)
    {
        if(st>= s.size())
        {
            res.push_back(sub);
        
        }
        
        for(int nd = st; nd < s.size(); nd++)
        {
             if (ispalin(s,st,nd))
             {
                 sub.push_back(s.substr(st,nd - st +1));
                 dfs(s,nd+1,sub);
                 sub.pop_back();//backtracking
             }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> sub;dfs(s,0,sub);
        return res;
    }
};