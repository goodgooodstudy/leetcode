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
    bool isPalindrome(ListNode* head) {
        ListNode* p1=head, *p2=head;
        while(p1 && p2 &&p1->next && p2->next){
            p1=p1->next;
            p2 = p2->next->next;
        }
        //reverse from p1
        ListNode* pre = nullptr, *next = nullptr,*cur = p1;
        while(cur){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        while(pre && head){
            if(pre->val!=head->val)return false;
            pre = pre -> next;
            head = head->next;
        }
        return true;
    }
};
