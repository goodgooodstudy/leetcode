class Solution {
public:
    unordered_map<string, vector<string>> dict;
    vector<string> square;
    vector<vector<string>>squares;
    vector<vector<string>> wordSquares(vector<string>& words) {
        if(words.size() == 0 || words[0].size() == 0) return squares;
        int n = words[0].size();
        square.resize(n);
        for(auto w : words){
            for(int i = 0; i < w.size(); i++){
                dict[w.substr(0,i)].push_back(w);
            }
        }
        build(0, n);
        return squares;
    }
    void build(int i, int n){
        if(i == n){
            squares.push_back(square);
            return;
        }
        string prefix;
        for(int k = 0; k < i; k++){
            prefix += square[k][i];
        }
        for(string s : dict[prefix]){
            square[i] = s;
            build(i+1,n);
        }
    }
    
};
