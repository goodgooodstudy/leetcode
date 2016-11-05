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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;  //!!! important to judge when there is only one
        ListNode* slow= head, *fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        fast = slow;
        slow = slow->next;
        fast->next = NULL;
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);
        return mergeList(l1,l2);
        
    }
    
    ListNode* mergeList(ListNode* l1, ListNode* l2){
        ListNode dummy(-1);
        ListNode* p = &dummy;
        for(; l1!=nullptr||l2 != nullptr; p = p->next){ // do not forget to p->next
            int v1 = l1 ==nullptr?INT_MAX:l1->val;
            int v2 = l2 == nullptr? INT_MAX:l2->val;
            if(v1 < v2){
                p->next = l1;
                l1 = l1->next;
            }
            else{
                p->next = l2;
                l2 = l2->next;
            }
        }
        return dummy.next;
        
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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* slow= head, *fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        fast = slow;
        slow = slow->next;
        fast->next = NULL;
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);
        return mergeList(l1,l2);
        
    }
    
    ListNode* mergeList(ListNode* l1, ListNode* l2){
        ListNode dummy(-1);
        ListNode* p = &dummy;
        for(; l1!=nullptr||l2 != nullptr; p = p->next){
            int v1 = l1 ==nullptr?INT_MAX:l1->val;
            int v2 = l2 == nullptr? INT_MAX:l2->val;
            if(v1 < v2){
                p->next = l1;
                l1 = l1->next;
            }
            else{
                p->next = l2;
                l2 = l2->next;
            }
        }
        return dummy.next;
        
    }
};
