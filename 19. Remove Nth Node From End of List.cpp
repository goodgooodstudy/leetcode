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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* one = new ListNode(0);
        one ->next = head;
        ListNode*r = one, *l = one;
        n = n+1;
        while(r!=NULL && n!=0){
            r = r->next;
            n--;
        }
        while(r!=NULL){
            r= r->next;
            l = l->next;
        }
        ListNode* del = l->next;
        l->next = del->next;
        delete(del);
        head= one->next;
        delete(one);
        return head;
        
        
        
        
        
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
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         ListNode* one = new ListNode(0);
//         one ->next = head;
//         ListNode*r = one, *l = one;

//         while( n!=0){
//             r = r->next;
//             n--;
//         }
//         while(r->next!=NULL){
//             r= r->next;
//             l = l->next;
//         }
//         ListNode* del = l->next;
//         l->next = del->next;
//         delete(del);
//         head= one->next;
//         delete(one);
//         return head;
        
        
        
        
        
//     }
// };
