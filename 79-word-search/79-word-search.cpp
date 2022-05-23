class Solution {
public:
    map<pair<int,int>, bool> visited;
   bool wordSearch(vector<vector<char>>& board, string word, int i, int j, int index) {
	if(index == word.size()) {
		return true;
	}
	int n = board.size();
	int m = board[0].size();
	if(i < 0 || j < 0 || i >= n || j >= m || board[i][j] != word[index] || visited[{i,j}] == 1) {
		return false;
	}
	visited[{i,j}] = 1;
	bool returnValue = wordSearch(board, word, i + 1, j, index + 1);
	returnValue |= wordSearch(board, word, i - 1, j, index + 1);
	returnValue |= wordSearch(board, word, i, j + 1, index + 1);
	returnValue |= wordSearch(board, word, i, j - 1, index + 1);
       
    visited[{i,j}] = 0;
	return returnValue;
}
bool exist(vector<vector<char>> board, string word) {
    int wordLen = word.size();
	if(wordLen == 0) {
		return true;
	}
	int n = board.size();
	int m = board[0].size();
	if(n == 0 || m == 0) {
		return 0;
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(board[i][j] == word[0]) {
				if(wordSearch(board, word, i, j, 0)) {
					return true;
				}
			}
		}
	}
	return false;
}
};