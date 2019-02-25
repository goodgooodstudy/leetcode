class LFUCache {
private:
    unordered_map<int, list<int>> freq; // freq, key
    unordered_map<int, pair<int, int>> data; // value, freq
    unordered_map<int, list<int>::iterator> freq_index;
    int size;
    int mn_freq;
public:
    LFUCache(int capacity) {
        size = capacity;
        mn_freq = 0;
    }
    
    int get(int key) {
        if(!freq_index.count(key)) return -1;
        pair<int,int> value = data[key];
        int freq_idx = value.second;
        int rst = value.first;
        auto it = freq_index[key];
        freq[freq_idx].erase(it);
        freq_idx++;
        freq[freq_idx].insert(freq[freq_idx].begin(), key);
        freq_index[key] = freq[freq_idx].begin();
        data[key].second = freq_idx;
        if(freq[mn_freq].size() == 0){
            mn_freq++;
        }
        return rst;
        
    }
    
    void put(int key, int value) {
        if(size <= 0) return;
        int storevalue = get(key);
        if(storevalue != -1){
            data[key].first = value;
            return;
        }
        if(freq_index.size() == size){
            auto it = freq[mn_freq].back();
            // freq[value.second].erase(it);
            data.erase(it);
                        // cout << key<<"erase"<<freq_index.size()<<data.size()<<endl;

            freq_index.erase(it);
            freq[mn_freq].pop_back();
            // cout << key<<"erase"<<freq_index.size()<<data.size()<<endl;
        }
        freq[1].insert(freq[1].begin(), key);
        mn_freq = 1;
        freq_index[key] = freq[1].begin();
        data[key].first = value;
        data[key].second = 1;
        // cout << freq_index.size()<<endl;
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
