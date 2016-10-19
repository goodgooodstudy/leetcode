class Solution {
public:
    /**
     * @param A an integer array
     * @return void
     */
    void sortIntegers2(vector<int>& A) {
        // Write your code here
        priority_queue<int, vector<int>, greater<int>> q(A.begin(),A.end());
        int idx = 0;
        while(!q.empty()){
            A[idx++] = q.top();
            q.pop();
        }
    }
};
