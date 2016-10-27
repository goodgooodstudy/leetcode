class Solution {
public:
    bool isAdditiveNumber(string num) {
        for(int i = 1; i <= num.size()/2; i++){
            for(int j = 1; j <= (num.size()-i)/2; j++){
                if(check(num.substr(0,i), num.substr(i,j), num.substr(i+j))) return true;
            }
        }
        return false;
    }
    
    bool check(string n1, string n2, string rest){
        if(n1.size()>1 && n1[0] == '0' || n2.size() >1 && n2[0] == '0') return false;
        string sum = add(n1, n2);
        if(sum == rest) return true;
        if(sum.size() >= rest.size() || sum!=rest.substr(0, sum.size()))return false;
        else return check(n2, sum, rest.substr(sum.size()));
    }
    
    string add(string n1, string n2){
        string res;
        int i = n1.size()-1, j = n2.size()-1, carry = 0;
        while(i>=0 || j>=0){
            int sum = carry + (i >=0 ?(n1[i--]-'0'):0) + (j >= 0? (n2[j--]-'0'):0);
            res.push_back(sum%10 + '0');
            carry = sum/10;
        }
        if(carry) res.push_back(carry+'0');
        reverse(res.begin(),res.end());
        return res;
    }
};
