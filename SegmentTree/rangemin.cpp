/**
* @Author: lcy
* @Date:   2016-10-27T13:48:21-04:00
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

//  get the index of mininal in a range

class SegmentTree{
private:
    vector<int> st;
    vector<int> A;
    int n;
    void build(int p, int L, int R){
        if(L == R){
            st[p] = L;
        }
        else{
            build(p*2, L, (L+R)/2);
            build(p*2+1, (L+R)/2+1, R);
            int p1 = st[p*2];
            int p2 = st[p*2+1];
            st[p] = A[p1] <= A[p2] ? p1:p2;
        }
    }
    int RMQ(int p, int L, int R, int i, int j){
        if(j < L || i > R) return -1;
        if( L >= i && R <= j) return st[p];
        int p1 = RMQ(p*2, L, (L+R)/2, i, j);
        int p2 = RMQ(p*2+1, (L+R)/2+1, R, i, j);
        if(p1 == -1) return p2;
        if(p2 == -1) return p1;
        return A[p1] <= A[p2] ? p1: p2;
    }
public:
    SegmentTree(const vector<int>& input){
        A = input;
        n = (int)input.size();
        st.assign(4*n, 0);
        build(1, 0, n-1);
    }
    int rmq(int i, int j){
        return RMQ(1, 0, n-1, i, j);
    }

};

int main(int argc, char* argv[]) {
    int arr[] = {18, 17, 13, 19, 15, 11, 20};
    vector<int> A(arr, arr+7);
    SegmentTree st(A);

    cout << "RMQ(1, 3) = " << st.rmq(1, 3) << endl;
    cout << "RMQ(4, 6) = " << st.rmq(4, 6) << endl;
}
