/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        return levelSum(nestedList, 1);
        
    }
    
    int levelSum(vector<NestedInteger>& nestedList, int level){
        int total = 0;
        for(int i = 0; i < nestedList.size(); i++){
            if(nestedList[i].isInteger()){
                total += nestedList[i].getInteger()*level;
            }
            else{
                total += levelSum(nestedList[i].getList(), level+1);
            }
        }
        return total;
    }
};
