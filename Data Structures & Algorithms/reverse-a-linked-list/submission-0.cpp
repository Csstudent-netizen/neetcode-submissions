/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return nullptr;
        if(head->next == nullptr) return head;
        ListNode *temp = head;
        head = head->next;
        temp->next = nullptr;
        while(head != nullptr){
            ListNode *t = temp;
            temp = head;
            head = head->next;
            temp->next = t;
        }

        return temp;
    }
};
