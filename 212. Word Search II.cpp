class Solution {
class Trie{
public:
    vector<Trie*> next;
    bool is_leaf;
    int idx;
    Trie():idx(-1),is_leaf(false),next(26, NULL){
    }
};
public:
    void insert(Trie* root,string& word, int idx ){
        for(int i = 0; i < word.size(); i++){
            if(root->next[word[i]-'a'] == NULL){
                root->next[word[i]-'a'] = new Trie();
            }
            root = root->next[word[i]-'a'];
        }
        root->is_leaf = true;
        root->idx = idx;
    }
    Trie* buildTrie(vector<string>& words){
        Trie* root = new Trie();
        for(int i = 0; i < words.size(); i++){
            insert(root, words[i], i);
        }
        return root;
        
    }
    void checkwords(vector<vector<char>>& board, int i, int j, int col, int row, Trie* root,vector<string>& res,vector<string>& words){
        char cur = board[i][j];
        if(cur == 'X') return;
        if(root->next[cur-'a'] == NULL) return;
        if(root->next[cur-'a']->is_leaf){
            res.push_back(words[root->next[cur-'a']->idx]);
            root->next[cur-'a']->is_leaf = false;
        }
        board[i][j] = 'X';
        if(i>0) checkwords(board, i-1, j, col, row, root->next[cur-'a'],res,words);
        if(i<row-1) checkwords(board,i+1, j, col, row, root->next[cur-'a'],res,words);
        if(j>0) checkwords(board, i, j-1, col, row, root->next[cur-'a'],res,words);
        if(j<col-1)checkwords(board,i,j+1,col,row,root->next[cur-'a'],res,words);
        board[i][j] = cur;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        int row = board.size();
        if(row == 0) return res;
        int col = board[0].size();
        if(col == 0) return res;
        if(words.size() == 0) return res;
        Trie* root = buildTrie(words);
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col&& res.size() < words.size(); j++){
                checkwords(board, i, j, col, row, root, res, words);
            }
        }
        return res;
        
    }
};
