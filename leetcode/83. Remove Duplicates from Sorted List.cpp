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
        ListNode * pre = head;
        if(!pre) return head;
        ListNode * cur = head->next;
        while(cur){
            if(  cur->val == pre->val){
                pre ->next = cur->next;
                cur = cur->next;
            }
            else{
                cur = cur->next;
                pre = pre->next;
            }
            
        }
        return head;
        
    }
};
