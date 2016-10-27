class Solution {
public:
    string simplifyPath(string path) {
        vector<string> pathes;
        string tmp,res;
        stringstream ss(path);
        while(getline(ss,tmp,'/')){
            if(tmp == "" || tmp == ".")continue;
            if(tmp == ".." && !pathes.empty()) pathes.pop_back();
            else if(tmp != "..")pathes.push_back(tmp);
        }
        for(auto p : pathes){
            res += "/"+p;
        }
        if(res.empty()) return "/";
        return res;
    }
};
