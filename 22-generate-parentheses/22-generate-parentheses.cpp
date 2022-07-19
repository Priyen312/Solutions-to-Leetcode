class Solution {
public:
    void generate(int m, string &s,int open, int close, vector<string> &res)
    {//nth catalan number O(4^n/n root(n)), O(4^n/n root(n))
        if(s.size() == m*2)
        {
            // if(!valid(s))
            // 	return;
            res.push_back(s);
            return;
        }

        if(open < m) 
        {
            s = s+'(';
            generate(m,s,open + 1, close, res);
            s.pop_back();
        }
        if(close < open) 
        {
            s = s + ')';
            generate(m,s,open, close+ 1, res);
            s.pop_back();
        }

    }
vector<string> generateParenthesis(int n) {
    // add your logic here
	vector<string> res;
	if(n == 0)
		return res;
    string s = "";
	generate(n,s,0,0,res);
	
	return res;
    
    }
};