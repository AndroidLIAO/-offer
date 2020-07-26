#include<iostream>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        vector<int>res;
        if (root == nullptr)return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            res.push_back(temp->val);
            if(temp->left!=nullptr)q.push(temp->left);
            if(temp->right!=nullptr)q.push(temp->right);
        }
        return res;
    }
};