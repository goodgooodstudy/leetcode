class TrieNode{
    public:
    bool is_word;
    vector<TrieNode*> next;
    TrieNode():is_word(false),next(26,NULL){
        
    }
};
class WordDictionary {
private:
    TrieNode* root;
    
public:
    WordDictionary(){
        root = new TrieNode();
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* tmp = root;
        for(int i = 0; i < word.size(); i++){
            if(tmp->next[word[i]-'a'] == NULL){
                tmp->next[word[i]-'a'] = new TrieNode();
            }
            tmp = tmp->next[word[i]-'a'];
        }
        tmp->is_word = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return query(word, root);
        
    }
    bool query(string word, TrieNode* node){
        TrieNode* tmp = node;
        for(int i = 0; i < word.size(); i++){
            if(word[i]!='.'){
                if(tmp->next[word[i]-'a']==NULL) return false;
                tmp = tmp->next[word[i]-'a'];
            }
            else{
                for(int j = 0; j<26;j++){
                    if(tmp->next[j]==NULL)continue;
                    if(query(word.substr(i+1),tmp->next[j]))return true;
                }
                return false;
            }
        }
        return tmp->is_word;
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
