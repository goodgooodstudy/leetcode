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
        ListNode* root = nullptr;
        if(head!=nullptr) pre(head, root);
        return root;
    }
    ListNode* pre(ListNode* head, ListNode* & root){
        if(head->next == nullptr){
            root = head;
            return head;
        }
        ListNode* next = head->next;
        head->next = nullptr;
        ListNode* newroot = pre(next, root);
        newroot->next = head;
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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        ListNode* pre = head;
        ListNode* cur = head->next;
        pre -> next = nullptr;
        ListNode* next;
        while(cur){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
   
};
