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
    ListNode* deleteNode(ListNode* head, int val) {
        if (head->val == val)return head->next;
        ListNode* node = head;
        ListNode* temp = head->next;
        while (temp != nullptr) {
            if (temp->val == val) {
                node->next = temp->next;
                break;
            }
            node = node->next;
            temp = temp->next;
        }
        return head;
    }
};