class LRUCache {
    list<int> cache;
    unordered_map<int, pair<int, list<int>::iterator> > mp;
    int csize;
public:
    LRUCache(int capacity) {
        csize=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        cache.erase(mp[key].second);
        cache.push_front(key);
        mp[key].second=cache.begin();
        return mp[key].first;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            // key found
            cache.erase(mp[key].second);
            
        } else {
            // key not found
            if(csize==cache.size()){
                int last=cache.back();
                cache.pop_back();
                mp.erase(last);
                
            }
        }
        cache.push_front(key);
        mp[key]={value, cache.begin()};
    }
};