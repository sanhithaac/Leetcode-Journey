class MyHashMap {
private:
    static const int SIZE = 1000; 
    vector<list<pair<int, int>>> buckets;

    int hash(int key) {
        return key % SIZE;
    }

public:
    MyHashMap() {
        buckets.resize(SIZE);
    }
    
    void put(int key, int value) {
        int idx = hash(key);
        
        for (auto &p : buckets[idx]) {
            if (p.first == key) {
                p.second = value;
                return;
            }
        }
        
        buckets[idx].push_back({key, value});
    }
    
    int get(int key) {
        int idx = hash(key);
        
        for (auto &p : buckets[idx]) {
            if (p.first == key) {
                return p.second;
            }
        }
        
        return -1;
    }
    
    void remove(int key) {
        int idx = hash(key);
        
        for (auto it = buckets[idx].begin(); it != buckets[idx].end(); it++) {
            if (it->first == key) {
                buckets[idx].erase(it);
                return;
            }
        }
    }
};