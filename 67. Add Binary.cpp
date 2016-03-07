class Solution {
public:

    string addBinary(string a, string b) {
        string c;
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int t1, t2, add;
        add = 0;
        for(int i = 0; i < a.size()||i < b.size(); i++){
            if(i >= a.size()) t1 = 0;
            else t1 = a[i] -'0';
            if(i >= b.size()) t2 = 0;
            else t2 = b[i] - '0';
            
            
            c.push_back((t1+t2+add)%2+'0');
            add = (t1+t2+add)/2;
        }
        if(add == 1) c.push_back('1');
        reverse(c.begin(),c.end());
        return c;
    }
};
