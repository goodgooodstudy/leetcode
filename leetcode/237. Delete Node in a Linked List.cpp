/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };这个题目有点问题。。。。可以直接改值*node = *(node->next)
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
       if(!node) return;
       ListNode* next = node->next;
       ListNode* pre = node;
       while(next){
           node->val = next->val;
           pre = node;
           node = next;
           next = next -> next;
       }
       pre->next = NULL;
       if(node)delete(node);
        
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
    void deleteNode(ListNode* node) {
        ListNode* cur = node;
        ListNode* next = cur->next;
        cur->val = next->val;
        while(next->next){
            cur = next;
            next = next->next;
            cur->val = next->val;
        }
        cur->next = nullptr;
        delete(next);
        
        
    }
};
