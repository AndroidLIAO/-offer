#include<iostream>
#include<deque>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (root == nullptr)return res;
		deque<TreeNode*> s;
		s.push_back(root);
		bool isleft = true;
		while (!s.empty()) {
			vector<int> path;
			int len = s.size();
			for (int i = 0; i < len; i++) {
				TreeNode* temp = s.front();
				s.pop_front();
				path.push_back(temp->val);
				if(temp->left)s.push_back(temp->left);
				if(temp->right)s.push_back(temp->right);
			}
			if (isleft)
				res.push_back(path);
			else
				res.push_back(vector<int>(path.crbegin(),path.crend()));
		}
		isleft = false;
		return res;
	}
};