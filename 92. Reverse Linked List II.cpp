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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* prehead = new ListNode(0);
        if(m == n) return head;
        prehead->next = head;
        ListNode* pre = prehead;
        int step = n-m;
        for(int i = 1; i <m; i++)
            pre = pre->next;
        ListNode* cur = pre -> next;
        ListNode* move;
        for(int i = 1; i <=n-m; i++){
            move = cur ->next;
            cur -> next = move->next;
            move->next = pre->next;
            pre->next = move;
        }
        return prehead->next;
        
        
        
    }
};
