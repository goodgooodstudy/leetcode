/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* root;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        root = head;
   
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int res = root->val;
        ListNode* tmp = root->next;
        int i = 2;
        while(tmp){
            int j = rand()%i;
            if(j == 0){
                res = tmp->val;
            }
            i++;
            tmp = tmp->next;
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
