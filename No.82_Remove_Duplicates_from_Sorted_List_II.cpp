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
        ListNode * dummpy= new ListNode(0);
        dummpy->next = head;
        ListNode* pre = dummpy;
        ListNode* index = head;
        bool duplicate = false;
        while(index){
            if(index->next != NULL && (index->val == index->next->val)){
                ListNode* tmp = index->next;
                index -> next = index->next->next;
                delete tmp;
                duplicate = true;
            }
            else if(duplicate ==true){
                ListNode* tmp = index;
                index = index->next;
                pre->next = index;
                delete tmp;
                duplicate = false;
                
            }
            else{
            pre = pre->next;
            index = index -> next;
                
            }

        }
        head = dummpy -> next;
        delete dummpy;
        return head;
        
    }
};
