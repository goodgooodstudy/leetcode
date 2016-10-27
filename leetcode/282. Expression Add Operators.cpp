class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        helper(res, "", num, target, 0, 0);
        return res;
    }
    void helper(vector<string>& res, string out,string num, int target, long long curNum, long long diff){
        if(num.size() == 0 &&curNum == target ){
            res.push_back(out);
        }
        for(int i = 1; i <= num.size(); i++){
            string cur = num.substr(0,i);
            if(cur.size() > 1 && cur[0] == '0') return;
            string next = num.substr(i);
            if(out.size() >0){
                helper(res, out+"+"+cur, next, target, curNum+stoll(cur), stoll(cur));
                helper(res, out+"-"+cur, next, target, curNum-stoll(cur), -stoll(cur));
                helper(res, out+"*"+cur, next, target,curNum-diff + diff*stoll(cur), diff*stoll(cur));
            }
            else{
                helper(res, cur, next, target, stoll(cur), stoll(cur));
            }
        }
    }
};
