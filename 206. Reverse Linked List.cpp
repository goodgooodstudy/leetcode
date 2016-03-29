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
    ListNode* reverseList(ListNode* head) {
        ListNode* pre=NULL, * next = NULL;
        while(head){
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }

};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        return reverse(head, NULL);
    }
    
    ListNode* reverse(ListNode* head, ListNode* node){
      if(head==NULL) return node;
      ListNode* next = head->next;
      head->next = node;
      return reverse(next, head);
    }
};
