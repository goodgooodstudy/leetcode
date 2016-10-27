class ZigzagIterator {
private:
    int p;
    vector<int>::iterator bs[2], es[2];
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        bs[0] = v1.begin();
        bs[1] = v2.begin();
        es[0] = v1.end();
        es[1] = v2.end();
        p = 0;
    }

    int next() {
        if(!hasNext()) return -1;
        if(bs[p] == es[p]){
            p = (p+1)%2;
        }
        int res = *bs[p];
        bs[p]++;
        p = (p+1)%2;
        return res;
    }

    bool hasNext() {
        return bs[0] != es[0] || bs[1] != es[1];
        
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
