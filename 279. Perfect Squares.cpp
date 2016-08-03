class Solution {
public:
    int numSquares(int n){
        vector<int> numSquares(n+1, n+1);
        numSquares[0] = 0;
        numSquares[1] = 1;
        for(int i = 2; i <=n;i++){
            for(int j = 1; j*j <=i; j++){
                numSquares[i] = min(numSquares[i],numSquares[i-j*j]+1);
            }
        }
        return numSquares[n];
    }
};
