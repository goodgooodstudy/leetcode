class Solution {

public:
    string multiply(string num1, string num2) {
        string s(1000,'0');
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        for (int i = 0; i < num1.size(); i++){
            for (int j = 0; j < num2.size(); j++){
  
                int tmp = (num1[i]-'0')*(num2[j] - '0');
                s[i+j+1] = (s[i+j+1]-'0') + (s[i+j] - '0' + tmp)/10 +'0';
                s[i+j] = (s[i+j] - '0' + tmp)%10 +'0';
                // cout << s[i+j] <<endl;
            }
        }
        reverse(s.begin(),s.end());
        if(s.find_first_not_of('0') == string::npos){
            return "0";
        }
        else return s.substr(s.find_first_not_of('0'));
    }
    
};
