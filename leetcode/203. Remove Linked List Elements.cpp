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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* pre = &dummy;
        ListNode* cur = head;
        while(cur){
            while(cur && cur->val!=val){
                pre = cur;
                cur = cur->next;
            }
            if(!cur) return dummy.next;
            pre->next = cur->next;
            cur = cur->next;
        }
        return dummy.next;
    }
};
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* p = new ListNode(-1);
        p->next = head;

        ListNode* cur = head;;
        ListNode* pre = p;
        while(cur!=NULL){
            if(cur->val == val){
                pre->next = cur->next;
                delete(cur);
                cur = pre->next;
            }
            else{
                pre = cur; 
                cur = cur->next;
            }
           
        }
        return p->next;
        
    }
};
