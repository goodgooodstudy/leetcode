class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> uglys;
        uglys.push_back(1);
        int idx1 =0, idx2 = 0, idx3 = 0;
        while(uglys.size()<n){
            int p1 = uglys[idx1]*2;int p2 = uglys[idx2]*3;int p3 = uglys[idx3]*5;
            int cur = min(p1,min(p2,p3));
            if(cur == p1)idx1++;
            if(cur == p2)idx2++;
            if(cur == p3)idx3++;
            if(cur > uglys.back())uglys.push_back(cur);
            
        }
        return uglys[n-1];
        
    }
};
/*Thoughts]
这就是多链表Merge Sort的一个扩展题。
对于任意一个ugly number - K, 2*K, 3*K, 和5*K都是ugly number，所以说新的ugly number都是从已有的ugly number上，通过与{2,3,5}相乘而产生的。
如果
Ugly Number:       1,         2,          3,           4,           5,           6,            8,         10,     ..............
那么                      1*2      2*2        3*2         4*2         5*2         6*2         8*2        10*2  .............. *2
                             1*3      2*3        3*3         4*3         5*3         6*3         8*3        10*3  .............. *3
                             1*5      2*5        3*5         4*5         5*5         6*5         8*5        10*5  .............. *5
都是ugly number。只要不断把新产生的ugly number通过merge sort添加到原有的ugly number数组中就可以了，直到找到第N个。*/
