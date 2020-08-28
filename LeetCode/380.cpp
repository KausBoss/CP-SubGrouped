class RandomizedSet {
public:
    /** Initialize your data structure here. */
    map<int, bool> m;
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        bool ret = m.count(val);
        m[val] = 1;
        return !ret;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        bool ret = m.count(val);
        if(ret){m.erase(val);}
        return ret;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        vector<int> v;
        for(auto x:m){v.push_back(x.first);}
        int size = v.size();
        int j = rand() % (size);
        
        return v[j];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */