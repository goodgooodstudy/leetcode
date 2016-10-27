class Solution {
// public:
//     bool isPrime(int n){
//         if(n <=1) return false;
//         for(int i = 2; i*i <= n; i++){
//             if(n%i == 0) return false;
//         }
//         return true;
//     }
//     int countPrimes(int n) {
//         int sum = 0;
//         for(int i =2; i <n; i++){
//             if(isPrime(i))sum++;
//         }
//         return sum;
        
//     }
public:
    int countPrimes(int n){
        vector<bool> isPrime(n,true);
        isPrime[1] = false;
        isPrime[0] = false;
        for(int i = 2; i*i < n; i++){
            if(!isPrime[i]) continue;
            for(int j = i*i; j < n; j = j+i){
                isPrime[j] = false;
            }
        }
        int sum = 0;
        for(int i = 2; i<n;i++){
            if(isPrime[i]) sum++;
        }
        return sum;
        
    }
};
