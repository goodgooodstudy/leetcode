class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded;
        for(string str: strs){
            encoded +=to_string(str.size())+"@"+str;
        }
        return encoded;
        
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int head = 0;
        while(head < s.size()){
            int at_pos = s.find_first_of("@",head);
            int len = stoi(s.substr(head,at_pos-head));
            res.push_back(s.substr(at_pos+1, len));
            head = at_pos+1+len;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
