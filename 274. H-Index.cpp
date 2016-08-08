class Solution {
public:
    // int hIndex(vector<int>& citations) {
    //     sort(citations.begin(),citations.end(),greater<int>());
    //     for(int i = 0; i< citations.size();i++){
    //         if(citations[i]<=i) return i;
    //     }
    //     return citations.size();
        
    // }
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if(n==0) return 0;
        vector<int> hash(n+1,0);
        for(int i = 0; i < citations.size(); i++){
            if(citations[i]>=n) hash[n]++;
            else hash[citations[i]]++;
        }
        int tot = 0;
        for(int i = n; i >=0; i--){
            tot+=hash[i];
            if(tot>=i) return i;
        }
        return n;
        
        
    }
};
