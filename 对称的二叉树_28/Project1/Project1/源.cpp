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
    /*递归解法*/
    /*bool isSymmetric(TreeNode* root) {
        if (root == nullptr)return true;
        return isSym(root->left, root->right);
    }
    bool isSym(TreeNode* left, TreeNode* right) {
        if (!left && !right)return true;
        if ((left && !right) || (!left && right))return false;
        if (left->val != right->val)return false;
        return isSym(left->left, right->right) && isSym(left->right, right->left);
    }*/
    /*迭代解法*/
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)return true;
        deque<TreeNode*> d;
        deque<TreeNode*> temp;
        //将根节点得左节点放入队列中
        d.push_back(root->left);
        //将根得右节点放入队列中
        d.push_back(root->right);
        while (!d.empty()) {
            //同时拿出左右节点
            TreeNode* left = d.front();
            d.pop_front();
            TreeNode* right = d.front();
            d.pop_front();
            if (!left && !right)continue;
            if ((left && !right) || (!left && right))return false;
            if (left->val != right->val)return false;
            //首先将左节点的左孩子放入队列中
            d.push_back(left->left);
            //再将右节点的右子树放入队列中,因为是左节点的左子树和右节点的右子树相比较，所以放入队列的顺序要相邻
            d.push_back(right->right);
            //再将左节点的右孩子放入队列中
            d.push_back(left->right);
            //再将右节点的左孩子放入队列中
            d.push_back(right->left);
        }
        return true;
    }
};