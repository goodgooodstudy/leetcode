class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int add=0;
        vector<int> sum;
        
        int i = digits.size()-1;
        if(i<0) return sum;
        sum.push_back( (digits[i]+1+add)%10 );
        add = (digits[i]+add+1)/10;

        while(--i >=0){
            sum.push_back( (digits[i]+add)%10 );
            add = (digits[i]+add)/10;
        }
        
        if(add == 1) sum.push_back(1);
        reverse(sum.begin(),sum.end());
        return sum;
        
    }
};
