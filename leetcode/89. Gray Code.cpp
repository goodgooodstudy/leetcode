class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> rst = {0};
        for(int i = 1; i <= n; i++){
            int n = rst.size();
            for(int idx = n-1; idx >= 0; idx--){
                int tmp = rst[idx] | 1 <<(i-1); //!!! use | not +
                rst.push_back(tmp);
            }
        }
        return rst;
    }
};

class Solution {
public:
    vector<int> grayCode(int n) {
        return generate(n);
        
    }
    
    vector<int> generate(int n){
        if(n==0) return vector<int>{0};
        else{
            vector<int> test = generate(n-1);
            vector<int> result;
            for(auto mem:test){
                result.push_back(mem);
            }
            for(int i = test.size()-1; i >= 0 ; i-- ){
                result.push_back(pow(2,n-1) + test[i]);
            }
            return result;
        }
    }
};
