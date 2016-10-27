class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> sorted_list;
        string result;
        int permutation = 1;
        for(int i = 1; i <= n; i++){
            sorted_list.push_back(i);
            permutation = permutation*i;
        }
        k = k-1;
        for(int i = 0; i < n;i++){
            permutation = permutation/(n-i);
            int index = k/permutation;
            result.push_back(sorted_list[index]+'0');
            sorted_list.erase(sorted_list.begin()+index);
            k = k%permutation;
        }
        // reverse(result.begin(),result.end());
        return result;
        
    }
};
