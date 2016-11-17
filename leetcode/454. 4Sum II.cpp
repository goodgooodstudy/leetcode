class Solution {
public:
    void fill(unordered_map<int, int>& sum1, vector<int>& A, vector<int>& B){
        for(int a : A){
            for(int b : B){
                sum1[a+b]++;
            }
        }
    }
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> sum1,sum2;
        fill(sum1, A, B);
        fill(sum2, C, D);
        int total = 0;
        for(auto p : sum1){
            if(sum2.count(0-p.first)){
                total += p.second*sum2[0-p.first];
            }
        }
        return total;
    }
};
