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
    /*�ݹ�ⷨ*/
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
    /*�����ⷨ*/
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)return true;
        deque<TreeNode*> d;
        deque<TreeNode*> temp;
        //�����ڵ����ڵ���������
        d.push_back(root->left);
        //�������ҽڵ���������
        d.push_back(root->right);
        while (!d.empty()) {
            //ͬʱ�ó����ҽڵ�
            TreeNode* left = d.front();
            d.pop_front();
            TreeNode* right = d.front();
            d.pop_front();
            if (!left && !right)continue;
            if ((left && !right) || (!left && right))return false;
            if (left->val != right->val)return false;
            //���Ƚ���ڵ�����ӷ��������
            d.push_back(left->left);
            //�ٽ��ҽڵ�����������������,��Ϊ����ڵ�����������ҽڵ����������Ƚϣ����Է�����е�˳��Ҫ����
            d.push_back(right->right);
            //�ٽ���ڵ���Һ��ӷ��������
            d.push_back(left->right);
            //�ٽ��ҽڵ�����ӷ��������
            d.push_back(right->left);
        }
        return true;
    }
};