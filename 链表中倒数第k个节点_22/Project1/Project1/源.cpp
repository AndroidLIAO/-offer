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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* node = head;
        int i = 0;
        while (i++ < k) {
            node = node->next;
        }
        ListNode* temp = head;
        while (node != nullptr) {
            temp = temp->next;
            node = node->next;
        }
        return temp;
    }
};