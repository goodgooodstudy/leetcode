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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        if(!head->next) return head;
        int val = head->val;
        ListNode* p = head->next;
        if(p->val!=val){
            head->next = deleteDuplicates(p);
            return head;
        }
        else{
            while(p && p->val == val) p = p->next;
            return deleteDuplicates(p);
        }
        
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head== NULL) return head;
        
        ListNode* fake = new ListNode(0);
        fake -> next = head;

        ListNode* pre, *index;
        pre = fake;
        
        index = head;
        while(index){
            
            while(index->next && index->val == index->next->val){
                index = index->next;
            }
            if(pre->next == index){
                pre = pre->next;
            }
            else{
                pre->next = index->next;
            }
            index = index->next;
        }
        return fake->next;
        
        
    }
};
