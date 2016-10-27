class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        for(auto num:nums){
            arr.push_back(to_string(num));
        }
        sort(arr.begin(), arr.end(),[](string& s1, string& s2){return s1+s2>s2+s2;});
        string res;
        for(auto s:arr){
            res+=s;
        }
        if(res.size()>0&&res[0] == '0') res = "0";
        return res;
        
    }
};


 bool great(string n1, string n2){
        return n1+n2 > n2+n2;
    }
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> ss;
        for(auto n : nums) {
            ss.push_back(to_string(n));
        }
        // cout << "Asd"<<endl;
        sort(ss.begin(), ss.end(), great);
        string rst;

        for(auto s : ss) rst+=s;
        int i = 0;
        while(i < rst.size() && rst[i] == '0') i++;
        return i == rst.size() ? "0":rst.substr(i);
        
        
    }
   
};
