class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        wordList.insert(endWord);
        queue<pair<string, int>> q;
        q.push(make_pair(beginWord,1));
        while(!q.empty()){
            string s = q.front().first;
            int len = q.front().second;
            if(s == endWord) return len;
            q.pop();
            vector<string> neighbors = findNeighbors(s, wordList);
            for(int i = 0; i < neighbors.size();i++){
                q.push(make_pair(neighbors[i],len+1));
            }
        }
        return 0;
    }
    
    vector<string> findNeighbors(string s, unordered_set<string>& wordList){
        vector<string> rst;
        for(int i =0; i<s.size();i++){
            char c = s[i];
            for(int j = 0; j<26;j++){
                if(c == 'a'+j) continue;
                s[i] = 'a'+j;
                if(wordList.count(s)){
                    rst.push_back(s);
                    wordList.erase(s);
                }
            }
            s[i] = c;
        }
        return rst;
    }
};
