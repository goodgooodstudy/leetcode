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
    ListNode* oddEvenList(ListNode* head) {
        // if(head==NULL || head->next ==NULL) return head;
        if(!head|| !head->next) return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = head->next;
        ListNode* index = head->next->next;
        
        bool is_odd = true;
        while(index){
            if(is_odd){
                odd->next = index;
                odd = odd ->next;
                is_odd = false;
                
            }
            else{
                even->next = index;
                even = even -> next;
                is_odd = true;
                
            }
            index = index ->next;
            
        }
        if(is_odd==false) even -> next = NULL;
        odd -> next = evenHead;

        return head;
    }
};
