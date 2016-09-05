class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<int, int> mp;
        mp[6] = 9;
        mp[9] = 6;
        mp[1] = 1;
        mp[0] = 0;
        mp[8] = 8;
        string upside;
        for(int i = 0; i < num.size(); i++){
            upside = to_string(mp[num[i]-'0']) + upside;
        }
        
        return upside == num;
        
    }
};
