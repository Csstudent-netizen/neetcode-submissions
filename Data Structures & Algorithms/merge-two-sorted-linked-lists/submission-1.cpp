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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && list2) return list2;
        else if(!list2 && list1) return list1;
        else if(!list1 && !list2) return nullptr;

        ListNode *head;
        ListNode *l1 = list1;
        ListNode *l2 = list2;
        if(l1->val <= l2->val){head = l1; l1 = l1->next;}
        else {head = l2; l2 = l2->next;}
        ListNode *t = head;
        
        while(l1 && l2){
            if(l1->val <= l2->val){
                t->next = l1;
                l1 = l1->next;
            }
            else{
                t->next = l2;
                l2 = l2->next;
            }
            t = t->next;
        }

        if(l1) t->next = l1;
        else t->next = l2;

        return head;
    }
};
