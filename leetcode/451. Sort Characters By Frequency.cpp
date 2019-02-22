class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> dict;
        for(char c : s) dict[c]++;
        vector<pair<char, int>> rst(dict.begin(), dict.end());
        auto f = [](pair<char, int> a, pair<char, int> b){
            return a.second > b.second;
        };
        sort(rst.begin(), rst.end(),f);
        string fs;
        for(auto p : rst){
            fs += string(p.second, p.first);
        }
        return fs;
    }
};
