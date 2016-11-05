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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       ListNode* p1 = headA;
       ListNode* p2 = headB;
       if(p1 == NULL || p2 == NULL) return NULL;
       while(p1!=NULL && p2 !=NULL && p1!=p2 ){
           p1 = p1->next;
           p2 = p2->next;
           if (p1 == p2) return p1;

           if(!p1) p1= headB;
           if(!p2) p2= headA;
       }
       return p1;
        
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        bool flip_p1 = true;
        bool flip_p2 = true;
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        while(p1 != p2){
            if(p1 == NULL && flip_p1 ){
               p1 = headB;
               flip_p1 = false;
            }
            else{
                p1 = p1->next;
            }
            if(p2 == NULL && flip_p2){
                p2 = headA;
                flip_p2 = false;
            }
            else{
                p2 = p2->next;
            }
            
            
        }
        return p1;
    }
};
