class TrieNode {
    
public:
    bool is_word;
    vector<TrieNode*>next ;

    // Initialize your data structure here.
    TrieNode(bool b=false):is_word(b),next(26,NULL) {
    }
};

class Trie {
public:

    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* tmp = root;
        for(int i = 0; i<word.size()&&tmp;i++){
            if(tmp->next[word[i]-'a']==NULL){
                tmp->next[word[i]-'a']=new TrieNode();
            }
            tmp = tmp->next[word[i]-'a'];
        }
        tmp->is_word = true;
        
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* tmp = find(word);
        return tmp!=NULL && tmp->is_word;
        
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        return find(prefix)!=NULL;
        
        
    }

private:
    TrieNode* root;
    
    TrieNode* find(string word){
        TrieNode* tmp = root;
        for(int i = 0; i < word.size()&&tmp; i++){
            tmp = tmp->next[word[i]-'a'];
        }        
        return tmp;
        
    }
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
