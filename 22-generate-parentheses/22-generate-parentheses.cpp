class Solution {
public:
    void generate(int m, string s,int open, int close, vector<string> &res)
{
	if(s.size() == m*2)
	{
		// if(!valid(s))
		// 	return;
		res.push_back(s);
		return;
	}
	
	if(open < m) generate(m,s+'(',open + 1, close, res);
	if(close < open) generate(m,s + ')',open, close+ 1, res);
	
}
vector<string> generateParenthesis(int n) {
    // add your logic here
	vector<string> res;
	if(n == 0)
		return res;
	generate(n,"",0,0,res);
	
	return res;
}
};