class MedianFinder {
public:
    priority_queue<int> small, large;
    // Adds a number into the data structure.
    void addNum(int num) {
        small.push(num);
        large.push(-small.top());
        small.pop();
        if(small.size() < large.size()){
            small.push(-large.top());
            large.pop();
        }
        
    }

    // Returns the median of current data stream
    double findMedian() {
        return small.size() > large.size() ?small.top():(small.top() - large.top())/2.0;
        
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();


class MedianFinder {
private:
    priority_queue<int, vector<int>, greater<int>> big;
    priority_queue<int, vector<int>, less<int>> small;
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        if(big.size() == 0){
            big.push(num);
            return;
        } 
        if(num > big.top()){
            big.push(num);
        }
        else small.push(num);
        if(big.size() < small.size()){
            big.push(small.top());
            small.pop();
        }
        else if(big.size() > small.size()+1){
            small.push(big.top());
            big.pop();
        }
        
    }

    // Returns the median of current data stream
    double findMedian() {
        if(big.size() == small.size()) return (big.top()+small.top())/2.0;
        else return big.top();
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
