#include<iostream>
#include<deque>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

class Solution {
public:
	TreeNode* mirrorTree(TreeNode* root) {
		/*
			采用递归的形式
		if (root == nullptr)return root;
		TreeNode* leftTree = mirrorTree(root->left);
		TreeNode* rightTree = mirrorTree(root->right);
		root->left = rightTree;
		root->right = leftTree;
		return root;
		*/

		//采用队列
		if (root == nullptr)return root;
		deque<TreeNode*> d;
		d.push_back(root);
		while (!d.empty()) {
			TreeNode* temp = d.front();
			d.pop_front();
			if (temp == nullptr)continue;//这里是因为当某个节点的左孩子/右孩子为空时，我们也将它压进去
			swap(temp->left, temp->right);
			d.push_back(temp->left);
			d.push_back(temp->right);
		}
		return root;

	}
};