class LRUCache {
public:
int cap;
    
    list<pair<int, int>> cacheList;
    
    // Hash map storing key -> iterator to node in cacheList
    unordered_map<int, list<pair<int, int>>::iterator> cacheMap;
    LRUCache(int capacity): cap(capacity)  {
        
    }
    
    int get(int key) {
        auto it = cacheMap.find(key);
        // Key not found
        if (it == cacheMap.end()) {
            return -1;
    }
    cacheList.splice(cacheList.begin(), cacheList, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = cacheMap.find(key);
        
        
        if (it != cacheMap.end()) {
            it->second->second = value;
            cacheList.splice(cacheList.begin(), cacheList, it->second);
            return;
        }
        
        if (cacheMap.size() == cap) {
            int lruKey = cacheList.back().first;
            cacheMap.erase(lruKey);
            cacheList.pop_back();
        }
        
       
        cacheList.push_front({key, value});
        cacheMap[key] = cacheList.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */