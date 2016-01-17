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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1&&!l2) return NULL;

        ListNode* result = new ListNode(-1);
        ListNode* pre = result;
        ListNode *p1 = l1, *p2 = l2;
        int carry = 0;
        
        while(p1 || p2){

            int v1 = p1 == NULL ? 0:p1->val;
            int v2 = p2 == NULL ? 0:p2->val;
            
            pre -> next = new ListNode((v1 + v2 + carry)%10);
            carry = (v1 + v2+ carry)/10;
            pre = pre -> next;
            
            p1 = p1 == NULL? NULL:p1->next;
            p2 = p2 == NULL? NULL:p2->next;
            
        }
        if(carry > 0) 
            pre->next = new ListNode(1);
        pre = result->next;
        delete result;
        return pre;
        
        
        
    }
};
