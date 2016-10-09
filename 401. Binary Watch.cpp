class Solution {
private:
    vector<int> hours = {8,4,2,1};
    vector<int> minutes = {32,16,8,4,2,1};
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> rst;
        helper(rst, num, 0, 0, 0);
        return rst;
    }
    void helper(vector<string>& rst, int num, int hour, int min, int begin){
        if(num == 0){
            string cur = to_string(hour);
            if(min < 10){
                cur=cur+":0"+to_string(min);
            }
            else cur = cur+":"+to_string(min);
            rst.push_back(cur);
            return;
        }
        for(int i = begin; i < hours.size()+minutes.size(); i++){
            if(i < hours.size()){
                hour += hours[i];
                if(hour < 12){
                    helper(rst, num-1, hour, min, i+1);
                }
                hour -= hours[i];
            }
            else{
                min += minutes[i-hours.size()];
                if(min < 60){
                    helper(rst, num-1, hour, min, i+1);
                }
                min -= minutes[i-hours.size()];
            }
        }
    }
};
