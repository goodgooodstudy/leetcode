class Solution {
public:
    string addStrings(string num1, string num2) {
    
        string rst="";
        int carry = 0;
        int idx1 = num1.size()-1, idx2 = num2.size()-1;
        while(idx1 >=0 || idx2 >=0 || carry > 0){
            long sum = 0;
            if(idx1>=0){sum+=num1[idx1]-'0'; idx1--;}
            if(idx2>=0){sum+=num2[idx2]-'0'; idx2--;}
            sum += carry;
            int cur = (sum)%10;
            carry = (sum)/10;
            rst = to_string(cur) + rst;
        }
        return rst;
        
    }
};
