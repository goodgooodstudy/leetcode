class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if(n == 0) return 0;
        int begin = 0, end = n;
        while(begin < end){
            int mid = (begin+end)/2;
            if(citations[mid] <n-mid)begin = mid+1;
            else end = mid;
        }
        return n-end;
        
    }
};
