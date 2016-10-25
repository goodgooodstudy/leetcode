class Vector2D {
private:
    vector<vector<int>>::iterator outer;
    vector<int>::iterator inner;
    vector<vector<int>>::iterator end;
public:
    Vector2D(vector<vector<int>>& vec2d) {
        outer = vec2d.begin();
        end = vec2d.end();
        if(outer!=vec2d.end()){
            inner = (*outer).begin();
        }
    }

    int next() {
        int res = *inner;
        inner++;
        return res;
        
    }

    bool hasNext() {
        if(outer == end){
            return false;
        }
        while(inner == (*outer).end()){
            outer++;
            if(outer == end) return false;
            inner = (*outer).begin();
        }
        return true;
        
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
