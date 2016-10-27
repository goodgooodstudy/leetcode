class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> allComb;
        string Comb;
        generate(n,0,0,Comb,allComb);
        return allComb;
        
    }
    void generate(int n, int left, int right, string s, vector<string>& all){
        if(left== n && right==n){
            all.push_back(s);
            return;
        }
        if(left<n){
            generate(n,left+1,right,s+'(',all);
        }
        if(right<left){
            generate(n,left,right+1,s+')',all);
        }
    }
};
