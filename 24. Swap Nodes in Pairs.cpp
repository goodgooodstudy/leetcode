/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* current = head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* tmp;
        while(current&&current->next){
            tmp = current->next;
            pre -> next = tmp;
            current->next = tmp->next;
            tmp->next = current;
            
            pre = current;
            current=current->next;
        }
        return dummy->next;
        
    }
};
