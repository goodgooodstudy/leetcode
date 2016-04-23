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
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(INT_MIN);
        for(ListNode* cur = head; cur!=NULL;){
            ListNode* tmp = cur->next;
            ListNode* pos = &dummy;
            while(pos->next!=NULL && pos->next->val < cur->val) pos = pos->next;
            cur->next = pos->next;
            pos->next = cur;
            cur = tmp;

        }
        
        return dummy.next;
    }
    
};
