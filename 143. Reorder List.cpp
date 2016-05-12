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
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode* one = head;
        ListNode* two = head;

        while(two && two->next){
            one = one->next;
            two = two->next->next;
        }
        if(one->next == NULL) return;
        two = one->next;
        one->next = NULL;
        
        // reverse the second one

        ListNode * pre = NULL;
        ListNode * current = two;
        ListNode * next;

        while(current){
            next = current->next;
            current -> next = pre;
            pre = current;
            current = next;

            
        }
        two = pre;
        one = head;
        ListNode* two_n, *one_n;
        while(two && one){
            two_n = two->next;
            one_n = one->next;
            one->next = two;
            two->next = one_n;
            one = one_n;
            two = two_n;
        }

        
    }
};
