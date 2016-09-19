/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int length = 0;
        ListNode* cur = head;
        while(cur){
            length++;
            cur = cur->next;
        }
        return BuildBST(head, 0, length-1);
    }
    TreeNode* BuildBST(ListNode*& head, int start, int end){
        if(start > end) return NULL;
        int mid = (start + end)/2;
        TreeNode* left = BuildBST(head, start, mid-1);
        TreeNode* root = new TreeNode(head->val);
        head = head->next;
        TreeNode* right = BuildBST(head, mid+1, end);
        root->left = left;
        root->right = right;
        return root;
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return helper(head, NULL);
        
    }
    TreeNode* helper(ListNode* left, ListNode* right){
        if(left == right) return NULL;
        ListNode* slow=left, *fast = left;
        while(fast != right && fast->next!=right){
            fast = fast->next->next;
            slow = slow->next; //1,2,3,4
        }
        TreeNode* root = new TreeNode(slow->val);
        root->left = helper(left, slow);
        root->right = helper(slow->next,right );
        return root;
        
    }
};
