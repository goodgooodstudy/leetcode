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
        if(head == NULL || head->next == NULL) return true; //do not forget
        
        ListNode* pre, *slow = head, *fast = head;
        while(fast && fast->next){
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;
        //reverse from slow
        ListNode* h2 = reverse(slow);
        ListNode* h1 = head;
        while(h1 && h2){
            if(h1->val != h2->val) return false;
            h1 = h1->next;
            h2 = h2->next;
        }
        return true;
        
        
    }
    ListNode* reverse(ListNode* head){
        ListNode* pre = head;
        if(head->next == NULL) return head;
        ListNode* cur = head->next;
        ListNode* next;
        pre->next = NULL;
        while(cur){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
        
        
    }
};
