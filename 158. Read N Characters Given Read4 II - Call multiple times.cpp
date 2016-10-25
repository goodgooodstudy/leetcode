// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
private:
    queue<char> q;
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        char buffer[4] = {0};
        int m = 0;
        while(q.size() < n && (m=read4(buffer)) > 0){
            for(int n = 0; n < m; n++)q.push(buffer[n]);
        }
        
        for(m = n; m > 0 && !q.empty(); m--,buf++){
            *buf = q.front();
            q.pop();
        }
        return n-m;
        
    }
};
