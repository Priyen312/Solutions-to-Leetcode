class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string help = strs[0];
        for(int i = 1 ; i< strs.size(); i++)
        {
            while(strs[i].find(help)!=0)//keep removin the last character until you find help in strs
            {
                help = help.substr(0,help.size()-1);
                if(help.size() == 0) return "";
            }
        }
        
        return help;
        
     
    }
};