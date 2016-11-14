class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        for(int i = 3; i <x.size(); i++){
            if(x[i] >= x[i-2] && x[i-1] <= x[i-3]){
                return true;
            }
            if(i >= 4){
                if(x[i]+x[i-4] >= x[i-2] && x[i-1] == x[i-3]){
                    return true;
                }
            }
            if(i >=5){
                if(x[i-2] - x[i-4] >= 0 && x[i-1] +x[i-5]>=x[i-3] && x[i-4] +x[i] >= x[i-2] && x[i-1] <= x[i-3]){
                    return true;
                }
            }
        }
        return false;
    }
};


class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
        for(int i = 0 ;i < x.size(); i++){
            f = e; e=d; d =c; c = b; b = a; a = x[i];
            if(i >= 3){
                if(d>= b && (a>=c || (a>=c-e && c-e >= 0 && b+f >= d)))
                    return true;
            }

        }
        return false;
    }
};
