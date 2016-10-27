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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* tmp = head;
        if(tmp == NULL) return head;
        int len = 1;
        while(tmp->next!=NULL){
            len++;
            tmp = tmp -> next;
        }
        tmp -> next = head;
        for(int i = 1; i<= len - k%len; i++){ // k > len!!!
            tmp = tmp->next;
        }
        head = tmp->next;
        tmp->next = NULL;
        return head;
        
    }
};
