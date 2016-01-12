class Solution {


public:
    string convert(string s, int numRows) {
        if (numRows < 2) return s;
        string convert;
        int zigsize = 2 * numRows - 2;
        for (int index = 0; index < s.size(); index = index + zigsize){
            convert+=s[index];
            }
        for (int i = 1; i < numRows-1; i++){
            for (int index = i; index < s.size(); index = index + zigsize){
                // convert.append(1,s[index]);
                convert += s[index];
                if(index + zigsize - 2*i < s.size()){
                    // convert.append(1,s[index + zigsize - 2*i]);
                    convert += s[index + zigsize - 2*i];
                }

            }
            
        }
        for (int index = numRows - 1; index < s.size(); index = index + zigsize){
            // convert.append(1,s[index]);
            convert += s[index];
        }

        return convert;
    }
};
