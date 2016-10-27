class Solution {
public:
     vector<int> split(const string &s, char delim) {
        stringstream ss(s);
        string item;
        vector<int> elems;
        while(getline(ss, item, delim)) {
            elems.push_back(atoi(item.c_str()));
        }
        return elems;
    }
    int compareVersion(string version1, string version2) {
        vector<int>f1 = split(version1,'.');
        vector<int>f2 = split(version2,'.');
        int n = min(f1.size(),f2.size());
        for(int i = 0; i < n; i++){
            if(f1[i] > f2[i]) return 1;
            else if(f1[i] < f2[i]) return -1;
        }
        if(f1.size() == f2.size()) return 0;
        else if(f1.size() > n){
            int i = n;
            while(i < f1.size() && f1[i] == 0)i++;
            if(i < f1.size() && f1[i]!=0) return 1;
            else return 0;
        }
        else{
            int i = n;
            while(i<f2.size() && f2[i] == 0) i++;
            if(i <f2.size()&&f2[i] !=0) return -1;
            else return 0;
        }

    }
};
