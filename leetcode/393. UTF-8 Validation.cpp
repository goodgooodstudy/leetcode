class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int idx = 0;
        while( idx < data.size()){
            int cnt = 0;
            if(data[idx] >> 7 == 0) cnt = 0;
            else if(data[idx] >> 5 == 0b110) cnt = 1;
            else if(data[idx] >> 4 == 0b1110) cnt = 2;
            else if(data[idx] >> 3 == 0b11110) cnt = 3;
            else return false;
            for(int i = 1; i <= cnt; i++){
                if(data[idx+i] >> 6 != 0b10) return false;
            }
            idx = idx + cnt+1;
        }
        
        return true;
        
    }
};
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int cnt = 0;
        for(auto  c:data){
            if(cnt == 0){
                if((c>>7) == 0b0) cnt = 0;
                else if((c >> 5) == 0b110)cnt = 1;
                else if((c>>4) ==0b1110)cnt = 2;
                else if((c>>3) ==0b11110)cnt = 3;
                else return false;
            }
            else{
                if((c >>6) != 0b10)return false;
                cnt--;
            }
        }
       return cnt == 0;
    }
  
};
