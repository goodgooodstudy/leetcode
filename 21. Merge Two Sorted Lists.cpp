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
    // ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    //     if(!l1) return l2;
    //     if(!l2) return l1;
    //     if(l1->val >= l2->val){
    //       l2->next = mergeTwoLists(l1, l2->next);
    //       return l2;
    //     }
    //     else{
    //         l1->next = mergeTwoLists(l1->next,l2);
    //         return l1;
    //     }
        
    // }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode(-1);
        ListNode* cur=dummy;
        while(l1 && l2){
            if(l1->val < l2->val){
                cur->next=l1;
                cur=l1;
                l1=l1->next;
            }
            else{
                cur->next=l2;
                cur=l2;
                l2=l2->next;
            }
        }
        if(!l1)  cur->next=l2;
        if(!l2)  cur->next=l1;
        return dummy->next;
    }
       
};
