class Solution {
public:
    /**
     * @param A an integer array
     * @return void
     */
    void sortIntegers2(vector<int>& A) {
        // Write your code here
        partition(A, 0, A.size()-1);
    }
    void partition(vector<int>& arr, int left, int right){
      if(left >= right) return;
      int i = left, j = right;
      int tmp;
      int pivot = arr[left+(-left + right) / 2];
 
      /* partition */
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  swap(arr[i], arr[j]);
                  i++;
                  j--;
            }
      };
 
      /* recursion */
      if (left < j)
            partition(arr, left, j);
      if (i < right)
            partition(arr, i, right);
    }
};
