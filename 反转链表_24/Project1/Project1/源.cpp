#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head)return head;
        ListNode H(0);
        ListNode* node = &H;
        ListNode* temp = head->next;
        ListNode* L = head;
        node->next = head;
        while (temp!= nullptr) {
            head->next = temp->next;//去除要移动的节点
            temp->next = L; //将节点放到首节点前面
            node->next = temp;//建立连接
            L = temp;//改变首节点
            temp = head->next;
        }
        return node->next;
    }
};