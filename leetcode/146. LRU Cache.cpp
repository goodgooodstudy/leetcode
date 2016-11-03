/**
* @Author: lcy
* @Date:   2016-09-03T12:50:54-04:00
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;



class LRUCache{
public:
    struct CacheEntry{
    public:
        int key;
        int value;
        CacheEntry(int k, int v):key(k),value(v){}
    };

    LRUCache(int capacity) {
       m_capacity = capacity;
    }

    int get(int key) {
        if(m_map.find(key) == m_map.end()){
            return -1;
        }
        MoveToHead(key);
        return m_map[key]->value;

    }

    void set(int key, int value) {
        if(m_map.find(key) == m_map.end()){
            CacheEntry cache(key, value);
            if(m_map.size() >= m_capacity){
                m_map.erase(m_cache.back().key);///!!!!!! do not forget!!
                m_cache.pop_back();
            }
            m_cache.push_front(cache);
            m_map[key] = m_cache.begin();
                return;
        }
        m_map[key]->value = value;
        MoveToHead(key);

    }



private:
    list<CacheEntry> m_cache;
    unordered_map<int,list<CacheEntry>::iterator> m_map;
    int m_capacity;

    void MoveToHead(int key){
        auto updateEntry = *m_map[key];//*iterator->val
        m_cache.erase(m_map[key]); //pos
        m_cache.push_front(updateEntry); //val
        m_map[key] = m_cache.begin();

    }
};
