class Solution {
private:
    vector<vector<char>> image;
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        this->image = image;
        int m = image.size();
        int n = image[0].size();
        int left = searchRow(0,y,0,m, true);
        int right = searchRow(y+1,n,0,m,false);
        int top = searchCol(0,x,left, right, true);
        int bottom = searchCol(x+1, m, left, right, false);
        // cout << left <<" "<<right << " "<<top <<" "<<bottom << endl;
        return (right -left)*(bottom - top);
        
    }
    int searchRow(int i, int j, int top, int bottom, bool opt){
        while(i < j){
            int mid = i + (j-i)/2;
            int k = top;
            while(k < bottom && image[k][mid] =='0') k++;
            if(k < bottom == opt){
                j = mid;
            }
            else{
                i = mid+1; //keep right cannot reach
            }
        }
        return i;
        
    }
    
    int searchCol(int i, int j, int left, int right, bool opt){
        while(i < j){
            int mid = i + (j-i)/2;
            int k = left;
            while(k < right && image[mid][k] == '0')k++;
            if(k < right == opt){
                j = mid;
            }
            else{
                i = mid +1;
            }
        }
        return i;
        
    }
};
