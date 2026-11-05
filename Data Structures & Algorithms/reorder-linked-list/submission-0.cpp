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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // CUT the list in half so they are completely separated
        ListNode* head2 = slow->next; 
        slow->next = nullptr;

        //reverse from head2
        ListNode* prev = nullptr;
        ListNode* curr = head2;
        while(curr != nullptr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        //merge
        ListNode* h = head;
        ListNode* hnext = h->next;
        ListNode* pnext = prev->next;
        while(h != nullptr && prev != nullptr){
            h->next = prev;
            prev->next = hnext;
            prev = pnext;
            h = hnext;
            hnext = hnext->next;
            pnext = pnext->next;
        }
    }
};
