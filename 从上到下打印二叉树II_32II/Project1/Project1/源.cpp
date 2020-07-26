#include<iostream>
#include<queue>
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
        if (!root)return res;
        queue<TreeNode*> q;
        q.push(root);
        while (true) {
            vector<int> path;
            queue<TreeNode*> que;
            while (!q.empty()) {
                TreeNode* temp = q.front();
                q.pop();
                path.push_back(temp->val);
                if(temp->left)que.push(temp->left);
                if(temp->right)que.push(temp->right);
            }
            res.push_back(path);
            if (que.empty())break;
            q = que;
        }
        return res;
    }
};