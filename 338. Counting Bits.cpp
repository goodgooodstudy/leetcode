class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> cnt(num+1,0);
        int pow = 1;
        int before=1;
        for(int i = 1; i <=num; i++){
            if(i == pow){
                cnt[i] = 1;
                pow = pow <<1;
                before = i;
            }
            else{
                cnt[i] = cnt[before]+cnt[i-before];
            }
        }
        return cnt;
    }
};

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> cnt(num+1,0);
        
        for(int i = 1; i <=num; i++){
            cnt[i] = cnt[i>>1] + (1&i);
        }
        return cnt;
    }
};
