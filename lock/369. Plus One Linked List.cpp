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
    ListNode* plusOne(ListNode* head) {
        int carry = helper(head);
        if(carry > 0){
            ListNode* root = new ListNode(carry);
            root->next = head;
            return root;
        }
        return head;
        
    }
private:
    int helper(ListNode* head){
        if(head == NULL) return 1;
        int carry = helper(head ->next);
        if(carry > 0){
            carry += head->val;
            head->val = carry%10;
        }
        return carry/10;
    }
};
