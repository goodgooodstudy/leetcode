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
    // ListNode* reverseKGroup(ListNode* head, int k) {
    //     if(head == NULL ||head->next == NULL || k<2) return head;
    //     ListNode* next_group = head;
    //     for(int i = 1; i <=k; i++){
    //         if(next_group){
    //             next_group = next_group->next;
    //         }
    //         else{
    //             return head;
    //         }
    //     }
    //     ListNode* new_next_group = reverseKGroup(next_group, k);
    //     ListNode* pre = NULL, *cur= head, *next = head->next;
    //     while(cur!=next_group){
    //         next = cur->next;
    //         cur->next = pre ? pre:new_next_group;
    //         pre = cur;
    //         cur = next;
    //     }
    //     return pre;
        
    // }
    ListNode* reverseKGroup(ListNode* head, int k){
        if(head == NULL || head->next == NULL || k<2) return head;
        ListNode dummy(-1);
        dummy.next = head;
        for(ListNode* prev = &dummy, *end = prev->next;end; end = prev->next){
            for(int i = 1; i <k && end; i++){
                end = end->next;
            }
            if(end == NULL) break;
            prev = reverse(prev, prev->next, end);
            
        }
        return dummy.next;
        
        
    }
    ListNode* reverse(ListNode* prev, ListNode* begin, ListNode* end){
        ListNode* end_next = end->next;
        ListNode* pre = NULL, *cur = begin, *next = cur->next;
        while(cur!=end_next){
            next = cur->next;
            cur->next = pre?pre:end_next;
            pre = cur;
            cur = next;
        }
        prev->next = pre;
        return begin;
    }
};
