/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return NULL;
        unordered_map<RandomListNode*, RandomListNode*> cp;
        RandomListNode* p1 = head;
        RandomListNode* p2 = new RandomListNode(head->label);
        cp[p1] = p2;
        while(p1){
            if(p1->next){
                if(cp.count(p1->next)){
                    p2->next = cp[p1->next];
                }
                else{
                    RandomListNode* p2n = new RandomListNode(p1->next->label);
                    p2->next = p2n;
                    cp[p1->next] = p2n;
                }
            }

            if(p1->random){
                if(cp.count(p1->random)){
                    p2->random = cp[p1->random];
                }
                else{
                    RandomListNode* p2r = new RandomListNode(p1->random->label);
                    p2->random = p2r;
                    cp[p1->random] = p2r;
                }
            }

            p1 = p1->next;
            p2 = p2->next;
        }
        return cp[head];
    }
};
