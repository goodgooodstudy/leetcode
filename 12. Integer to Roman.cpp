class Solution {
public:
    string intToRoman(int num) {
        string dict[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int val[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string ret;
        for (int i = 0; i < 13; i++){
            if(num > 0){
                int count = num/val[i];
                num = num%val[i];
                for (int j = 0; j< count; j++){
                    ret.append(dict[i]);
                }
            }
            
        }
        return ret;

            
        
        
    }
};
