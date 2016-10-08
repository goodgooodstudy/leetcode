class Solution {
public:
    string removeKdigits(string num, int k) {
        string rst = "";
        int n = num.size();
        int digit = n - k;
        if(num.size() -k ==0){
            return "0";
        } 
        for(int i = 0; i < n; i++){
            while(!rst.empty()&&num[i] < rst.back()&&k>0){
                rst.pop_back();
                k--;
            }
            rst+=num[i];
            
        }

        int idx = 0;
        while(idx < rst.size()&&rst[idx] == '0') idx++;
        return idx == digit ? "0" : rst.substr(idx,digit);
        
    }
};
