class Solution {
public:
    /**
     * @param A an integer array
     * @return void
     */
    void sortIntegers2(vector<int>& A) {
        // Write your code here
        mergesort(A, 0, A.size()-1);
    }
    void mergesort(vector<int>& A, int l, int r){
        if(l >= r) return;
        int mid = l + (r-l)/2;
        mergesort(A, l, mid);
        mergesort(A, mid+1, r);
        int idx1 = l, idx2 = mid+1;
        vector<int> tmp;
        while(idx1 <= mid || idx2 <=r){
            int n1 = (idx1 <= mid)? A[idx1]:INT_MAX;
            int n2 = (idx2 <= r)?A[idx2]:INT_MAX;
            if(n1 < n2){
                tmp.push_back(n1);
                idx1++;
            }
            else{
                tmp.push_back(n2);
                idx2++;
            }
        }
        for(int i=0; i < tmp.size(); i++) A[l+i] = tmp[i];
        
    }
};
