// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int res = 0;
        for(int i = 0, cur = 4; i <= n/4 && cur == 4; i++){
            cur = read4(res+buf);
            res += cur;
        }
        return min(res,n);
        
    }
};
