class Solution {
public:
    bool judgeCircle(string moves) {
        int y = 0;
        int x = 0;
        for(char s : moves){
            if(s == 'U') y++;
            if(s == 'D') y--;
            if(s == 'L') x--;
            if(s == 'R') x++;
        }
        if(x == 0 && y == 0) return true;
        else return false;
        
    }
};