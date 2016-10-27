class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> elements(n,0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j <words[i].size(); j++){
                elements[i] |= 1 << (words[i][j]-'a');
            }
        }
        int ans = 0;
        for(int i = 0; i<n;i++){
            for(int j = i+1; j < n; j++){
                if(!(elements[i] & elements[j])){
                    int tmp = words[i].size() * words[j].size();
                    ans = max(ans,tmp);
                }
            }
        }
        return ans;
        
        
        
    }
};
