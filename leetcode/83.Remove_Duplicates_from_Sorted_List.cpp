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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return head;
        ListNode* index = head;
        ListNode* p = head->next;
        while(p != NULL){
            if(index->val == p->val){
                ListNode* tmp = p;
                p = p->next;
                index ->next = p;
                delete tmp;
                continue;
            }
            index = index->next;
            p = p->next;
            
        }
        return head;
    }
};
