class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> rst;
        
        while(n!=1){
            if(rst.count(n)) return false;
            rst.insert(n);
            int sum = 0;
            while(n > 0){
                sum += (n%10)*(n%10);
                n = n/10;
            }
            n = sum;
        }
        return true;
        
    }
};
