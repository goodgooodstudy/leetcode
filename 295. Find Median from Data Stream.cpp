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
