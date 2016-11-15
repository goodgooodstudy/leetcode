class RandomizedCollection {
private:
    vector<pair<int, int>> nums;
    unordered_map<int, vector<int>> dict;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool rst = (dict.count(val) > 0);
        int idx_dict = dict[val].size();
        nums.emplace_back(val, idx_dict);
        dict[val].push_back(nums.size()-1);
        return !rst;

    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        bool rst = (dict.count(val) > 0);
        if(rst){
            auto last = nums.back();
            dict[last.first][last.second] = dict[val].back();
            nums[dict[val].back()] = last;
            nums.pop_back();
            dict[val].pop_back();
            if(dict[val].size() == 0) dict.erase(val);
        }
        return rst;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand()%nums.size()].first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
