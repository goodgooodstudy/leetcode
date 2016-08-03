class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int m = primes.size();
        vector<int>idxlist(m,0);
        vector<int>uglys;
        uglys.push_back(1);
        while(uglys.size() <n){
            int min = INT_MAX;
            int update = 0;
            for(int i = 0; i <m; i++){
                if(uglys[idxlist[i]]*primes[i] < min){
                    min = uglys[idxlist[i]]*primes[i];
                    update = i;
                }
            }
            idxlist[update]++;
            if(min > uglys.back()){
                uglys.push_back(min);
            }
            
        }
        return uglys[n-1];
        
    }
};
