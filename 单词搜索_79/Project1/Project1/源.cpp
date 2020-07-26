#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		if (board.empty() || board[0].empty())return false;
		int m = board.size();
		int n = board[0].size();
		vector<vector<bool>>used(m, vector<bool>(n, false));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (dfs(board, used, word, 0, i, j))return true;
			}
		}
		return false;
	}
	bool dfs(vector<vector<char>> board, vector<vector<bool>>& used, string word, int len, int ch1, int ch2) {
		if (len == word.size())return true;
		/*for (int i = ch1; i < board.size(); i++) {
			for (int j = ch2; j < board[0].size(); j++) {
				if (board[i][j] == word[len]) {
					path += board[i][j];
					if (dfs(board, used, word, len + 1, ch1 + 1, ch2) || dfs(board, used, word, len + 1, ch1 - 1, ch2) ||
						dfs(board, used, word, len + 1, ch1, ch2 + 1) || dfs(board, used, word, len + 1, ch1, ch2 - 1)) {
						return true;
					}
					used[i][j] = false;
					path.pop_back();
				}
			}
		}*/
		if (ch1 < 0 || ch1 >= board.size() || ch2 < 0 || ch2 >= board[0].size()||board[ch1][ch2]!=word[len])return false;
		if (used[ch1][ch2] == false) {
			used[ch1][ch2] = true;
			if (dfs(board, used, word, len + 1, ch1 + 1, ch2) || dfs(board, used, word, len + 1, ch1 - 1, ch2) ||
				dfs(board, used, word, len + 1, ch1, ch2 + 1) || dfs(board, used, word, len + 1, ch1, ch2 - 1)) {
				return true;
			}
			used[ch1][ch2] = false;
		}
		return false;
	}
};