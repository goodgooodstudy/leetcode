class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int n = min(k, int(matrix.size()));
        if(n==0) return 0;
        priority_queue<int, vector<int>,cmp>heap;
        for(int i = 0; i < n; i++){
            for(int j = 0; j<n; j++){
                if(heap.size() < k){
                    heap.push(matrix[i][j]);
                }
                else if(matrix[i][j] < heap.top()){
                    heap.pop();
                    heap.push(matrix[i][j]);
                }
            }
        }
        return heap.top();
        
    }
    struct cmp{
        bool operator()(int a, int b){return a < b;}
    };
};


class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        if(min(n,k) == 0) return 0;
        auto cmp = [&matrix](pair<int, int>a, pair<int, int>b){return matrix[a.first][a.second]>matrix[b.first][b.second];};
       priority_queue<pair<int, int>, vector<pair<int,int>>,decltype(cmp)> heap(cmp);
       heap.emplace(0,0);
       int ans;
       while(k-- > 0 && heap.size()){
           auto pair = heap.top();
           ans = matrix[pair.first][pair.second];

           heap.pop();
           if(pair.second + 1 < n ){
               heap.emplace(pair.first,pair.second+1);
           }
           if(pair.second == 0 && pair.first+1 < n){
               heap.emplace(pair.first+1, pair.second);
           }
           
       }

       return ans;
        
    }

};
