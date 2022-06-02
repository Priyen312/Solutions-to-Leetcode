class Solution {
public:
void combo(int index,vector<int> &current, vector<vector<int>> &all,int n, int k)
{
	if(current.size() == k)
	{
		all.push_back(current);
		return;
	}
	
	for(int i = index; i <= n; i++)
	{
		current.push_back(i);
		combo(i + 1,current,all,n,k);
		current.pop_back();
	}
}

vector<vector<int> > combine(int n, int k) {
    // add your logic here
	vector<vector<int>> allcombinations;
	vector<int> currentcombination;
	combo(1, currentcombination, allcombinations, n , k);
	return allcombinations;
}

};