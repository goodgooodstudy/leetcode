/**
* @Author: lcy
* @Date:   2016-10-26T16:47:00-04:00
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
//  156. Binary Tree Upside Down   QuestionEditorial Solution  My Submissions
// Total Accepted: 16696
// Total Submissions: 40482
// Difficulty: Medium
// Contributors: Admin
// Given a binary tree where all the right nodes are either leaf nodes with a sibling (a left node that shares the same parent node) or empty, flip it upside down and turn it into a tree where the original right nodes turned into left leaf nodes. Return the new root.
//
// For example:
// Given a binary tree {1,2,3,4,5},
//     1
//    / \
//   2   3
//  / \
// 4   5
// return the root of the binary tree [4,5,2,#,#,3,1].
//    4
//   / \
//  5   2
//     / \
//    3   1
// confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
//
// Show Company Tags
// Show Tags
// Show Similar Problems

class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        TreeNode* newroot = NULL;
        helper(root, newroot);
        return newroot;

    }
    TreeNode* helper(TreeNode* root, TreeNode* & allroot) {
        if(!root || (!root->left && !root->right)){
             allroot = root;
             return root;
        }

        TreeNode* left = root->left;
        TreeNode* right = root->right;
        root->left = NULL;
        root->right = NULL;
        TreeNode* newroot = helper(left, allroot);
        newroot->right = root;
        newroot->left = right;
        return newroot->right;
    }
};
