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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode(-1);
        ListNode* cur=dummy;
        while(l1 && l2){
            if(l1->val < l2->val){
                cur->next=l1;
                cur=l1;
                l1=l1->next;
            }
            else{
                cur->next=l2;
                cur=l2;
                l2=l2->next;
            }
        }
        if(!l1)  cur->next=l2;
        if(!l2)  cur->next=l1;
        return dummy->next;
    }
          
    ListNode *mergeKLists(vector<ListNode *> &lists) {
           if(lists.empty()) return NULL;
           
           while(lists.size()>1){
               lists.push_back(mergeTwoLists(lists[0],lists[1]));
               lists.erase(lists.begin());
               lists.erase(lists.begin());

           }
           return lists.front();
           
    }
     
};
