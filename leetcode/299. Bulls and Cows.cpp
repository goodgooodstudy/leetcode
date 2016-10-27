class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        vector<int> cnt(10,0);
        int bulls = 0,cows = 0;
        for(int i = 0; i < n; i++){
            if(secret[i] == guess[i])bulls++;
            else{

                cnt[secret[i]-'0']++;
                cnt[guess[i]-'0']--;
                if(cnt[guess[i]-'0'] >= 0 ){
                    cows++;
                }
                if(cnt[secret[i]-'0'] <=0 ){
                    cows++;
                }
            }
        }
        return to_string(bulls)+"A"+to_string(cows)+"B";
        
    }
};
