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
    ListNode* partition(ListNode* head, int x) {
        ListNode node0(0), node1(0);
        ListNode* p1 = &node0, *p2 = &node1;
        while(head){
            if(head->val < x){
                p1 -> next = head;
                p1 = p1 ->next;
            }
            else{
                p2->next = head;
                p2 = p2 -> next;
            }
            head = head -> next;
        }
        p1->next = node1.next;
        p2->next = NULL;
        return node0.next;
        
        
    }
};
