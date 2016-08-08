// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
       int begin = 1, end=n;
       while(begin<end){
           int mid = begin+(end - begin)/2;//avoid overflow!!!
           if(!isBadVersion(mid)){
               begin = mid+1;
           }
           else end = mid;
       }
        return end;
    }
};
