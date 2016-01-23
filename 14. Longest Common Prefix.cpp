class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        if(strs.size() == 1) return strs[0];
        
        int length = strs[0].size();
        for(int i = 1; i < strs.size();i++){
            length = min(length, (int)strs[i].size());
        }
        if(length == 0) return "";
        
        string tmp = strs[0];
        int ret = 0;
        int index = 0;
        for (; index < length; index++){
            bool flag = true;
            for(int i = 1; i< strs.size(); i++){
                if(strs[i][index]!=tmp[index]){
                    flag = false;
                    break;
                }
            }
            if(!flag){
                ret = index;
                break;
            }
            
        }
        if(index == length) ret = index;
        return tmp.substr(0,ret);
        
    }
};
