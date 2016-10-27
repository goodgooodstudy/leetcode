class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int x1 = max(E,A);
        int x2 = max(min(G,C),x1);
        int y1 = max(F,B);
        int y2 = max(min(D,H),y1);
        int common = (x2-x1)*(y2-y1);
        int s1 = (C-A)*(D-B);
        int s2 = (G-E)*(H-F);
        return s1+s2-common;
        
    }
};
