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
			���õݹ����ʽ
		if (root == nullptr)return root;
		TreeNode* leftTree = mirrorTree(root->left);
		TreeNode* rightTree = mirrorTree(root->right);
		root->left = rightTree;
		root->right = leftTree;
		return root;
		*/

		//���ö���
		if (root == nullptr)return root;
		deque<TreeNode*> d;
		d.push_back(root);
		while (!d.empty()) {
			TreeNode* temp = d.front();
			d.pop_front();
			if (temp == nullptr)continue;//��������Ϊ��ĳ���ڵ������/�Һ���Ϊ��ʱ������Ҳ����ѹ��ȥ
			swap(temp->left, temp->right);
			d.push_back(temp->left);
			d.push_back(temp->right);
		}
		return root;

	}
};