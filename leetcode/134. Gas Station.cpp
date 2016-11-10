class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int mn = INT_MAX; // or change to zero do not have to % gas.size()
        int idx = -1;
        int total = 0;
        for(int i = 0; i < gas.size(); i++){
            total += gas[i]-cost[i];
            if(total < mn){
                mn = total;
                idx = i;
            }
        }
        if(total >= 0) return (idx+1)%gas.size();
        else return -1;
    }
};
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0;
        int total = 0;
        int index = -1;
        for(int i = 0; i<gas.size(); i++){
            sum+= gas[i] - cost[i];
            total += gas[i] - cost[i];
            if(sum < 0){
                sum = 0;
                index = i;
            }
        }
        if(total >= 0) return index+1 < gas.size()?index+1:0;
        else return -1;
    }
};
