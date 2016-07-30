// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int low = 1, high = n;
        while(low <= high){
            int mid = low + ((high-low) >>1);
            // int mid = (low+high)/2; 超时。。。。
            // int mid = (low+high) >>1; 
            int ans = guess(mid);
            if(ans == 0) return mid;
            else if(ans < 0) high = mid-1;
            else low = mid+1;
        }
        return low;
    }
    
};
