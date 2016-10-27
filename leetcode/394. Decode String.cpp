class Solution {
public:
    string decodeString(string s) {
        stack<string> nums;
        string cur;
        string all;
        for(int i = 0; i < s.size(); i++){
            if(s[i] >= 'a' && s[i] <='z'){
                cur += s[i];
            }
            else if(s[i]=='['){
                continue;
            }
            else if(s[i] == ']'){
                int rep = stoi(nums.top());
                nums.pop();
                string pre = nums.top();
                nums.pop();
                string total="";
                for(int i = 1; i <=rep; i++){
                    total += cur;
                }
                cur = pre+total;

            }
            else{
                int num = 0;
                while(s[i]>='0'&&s[i]<='9'){
                    num = num*10+s[i]-'0';
                    i++;
                }
                nums.push(cur);
                cur = "";
                nums.push(to_string(num));
                i--;
            }
        }
        return cur;
        
    }
};
