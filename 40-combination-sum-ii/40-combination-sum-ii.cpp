class Solution {
public:
    void findAllCombinations (vector<int>& A, int target, int index, vector<vector<int>> &result, vector<int> &current) {
	if (target == 0) 
	{
		result.push_back(current);
		return;
	}
	if (index == A.size() || target < 0 ) 
	{
		return;
	}
	
	current.push_back(A[index]);
	
	findAllCombinations (A, target - A[index], index + 1, result, current);
	while(index + 1 < A.size() && A[index] == A[index + 1]  )
		index++;
	current.pop_back();
	findAllCombinations(A, target, index + 1, result, current);      
}	

vector<vector<int> > combinationSum2(vector<int> &A, int val) {
    // add your logic here
	sort(A.begin(),A.end());
	vector<int> current;
	vector<vector<int>> result;
	findAllCombinations(A,val,0,result,current);
	return result;
	
}
};