class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        for(int i = 0; i<input.size(); i++){
            char c = input[i];
            if(ispunct(c)){
                vector<int> r1 = diffWaysToCompute(input.substr(0,i));
                vector<int> r2 = diffWaysToCompute(input.substr(i+1));
                for(int a :r1){
                    for(int b:r2){
                        res.push_back(c=='+'?a+b:c=='-'?a-b:a*b);
                    }
                }
            }
        }
        return res.size() == 0 ?vector<int>({stoi(input)}):res;
        
    }
};
