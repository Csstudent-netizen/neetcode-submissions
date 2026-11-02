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
    bool hasCycle(ListNode* head) {
        if(head == nullptr) return false;
        ListNode *fast = head;
        ListNode *slow = head;

        while(1){
            slow = slow->next;
            if(fast->next != nullptr) fast = fast->next->next;
            else return false;

            if(fast == nullptr) return false;
            else if(fast == slow) return true;
        }
    }
};
