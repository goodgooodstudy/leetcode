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
