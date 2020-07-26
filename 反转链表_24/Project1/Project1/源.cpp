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
            head->next = temp->next;//ȥ��Ҫ�ƶ��Ľڵ�
            temp->next = L; //���ڵ�ŵ��׽ڵ�ǰ��
            node->next = temp;//��������
            L = temp;//�ı��׽ڵ�
            temp = head->next;
        }
        return node->next;
    }
};