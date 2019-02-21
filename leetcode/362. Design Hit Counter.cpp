class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {
        
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        q.push(timestamp);
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while(!q.empty() && timestamp - q.front() >= 300){
            q.pop();
        }
        return q.size();
        
    }
private:
    queue<int> q;
};

// What if the number of hits per second could be very large? Does your design scale?

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */



class HitCounter {
private:
    queue<pair<int,int>> pq;
    int cnt;
public:
    /** Initialize your data structure here. */
    HitCounter() {
        cnt = 0;
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        while(!pq.empty() && timestamp - pq.front().first >= 300){
            cnt -= pq.front().second;
            pq.pop();
        }
        cnt ++;
        if(!pq.empty() && timestamp == pq.back().first) pq.back().second+=1;
        else pq.push(make_pair(timestamp, 1));
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while(!pq.empty() && timestamp - pq.front().first >= 300){
            cnt -= pq.front().second;
            pq.pop();
        }
        return cnt;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */
