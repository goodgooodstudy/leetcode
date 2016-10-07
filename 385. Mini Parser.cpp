/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        int i = 0;
        if(i<s.size()&&s[0]=='[') i++;
        NestedInteger rst =  helper(s,i);
        if(s.size() >0 && s[0] !='['&&rst.getList().size() == 1){
            return rst.getList()[0];
        }
        return rst;
    }
    NestedInteger helper(string& s, int& i){
        NestedInteger rst;
        int sign = 1;
        
        while(i < s.size()&&s[i]!=']'){
            if(s[i]=='+' || s[i] =='-'){
                sign = s[i] =='+'?1:-1;
                i++;
            }
            else if(s[i] >='0'&&s[i]<='9'){
                int num = 0;
                while(isdigit(s[i])){
                    num = num*10 + s[i]-'0';
                    i++;
                }
                num = sign*num;

                NestedInteger tmp;
                tmp.setInteger(num);
                sign = 1;
                rst.add(tmp);
                
            }
            else if(s[i] == '['){
                i++;
                NestedInteger cur = helper(s,i);
                i++;
                rst.add(cur);
            }
            else if(s[i] == ','){
                i++;
            }
        }
        // if(rst.getList().size() == 1){
        //     return rst.getList()[0];
        // }
        return rst;
        
    }
};
