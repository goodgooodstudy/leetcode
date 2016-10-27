class PhoneDirectory {
private:
    vector<int> phones;
    vector<bool> freelist;
    int idx, n;
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers):idx(0),n(maxNumbers),phones(maxNumbers,0),freelist(maxNumbers,true) {
        for(int i = 0; i < n; i++){
            phones[i] = i;
        }
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        int number = -1;
        if(idx < n){
            number = phones[idx++];
            freelist[number] = false;
        }
        return number;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        if(number < 0 || number >= n) return false;
        return freelist[number];
        
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if(number < 0 || number >= n || freelist[number]) return ;
        phones[--idx] = number;
        freelist[number] = true;
        
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */
