/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int m = grid.size();
        return helper(grid, 0, 0, m);
        
    }
    Node* helper(vector<vector<int>>& grid, int i, int j, int len){
        if(len == 1){
            return new Node(grid[i][j] == 1, true, nullptr, nullptr, nullptr, nullptr);
        }
        Node* l1 = helper(grid, i, j, len/2);
        Node* l2 = helper(grid, i, j+len/2, len/2);
        Node* l3 = helper(grid, i+len/2, j, len/2);
        Node* l4 = helper(grid, i+len/2, j+len/2, len/2);
        bool val = true;
        if(!l1->isLeaf || !l2->isLeaf || l1->val != l2->val){
            val = false;
        }
        if(!l2->isLeaf || !l3->isLeaf || l2->val != l3->val){
            val = false;
        }
        if(!l3->isLeaf || !l4->isLeaf || l3->val != l4->val){
            val = false;
        }
        Node* root = new Node();
        if(val){
            root->val = l1->val;
            root->isLeaf = true;
            root->topLeft = nullptr;
            root->topRight = nullptr;
            root->bottomLeft = nullptr;
            root->bottomRight = nullptr;
            delete l1, l2, l3,l4;
        }else{
            root->isLeaf = false;
            root->val = true;
            root->topLeft = l1;
            root->topRight = l2;
            root->bottomLeft = l3;
            root->bottomRight = l4;
        }
        return root;
    }
};
