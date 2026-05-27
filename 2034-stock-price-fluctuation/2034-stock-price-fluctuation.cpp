class StockPrice {
public:
    unordered_map<int,int> mp;
    multiset<int> s;
    int latest = 0;

    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        
        if(mp.count(timestamp)) {
            s.erase(s.find(mp[timestamp]));
        }

        mp[timestamp] = price;
        s.insert(price);

        latest = max(latest, timestamp);
    }
    
    int current() {
        return mp[latest];
    }
    
    int maximum() {
        return *s.rbegin();
    }
    
    int minimum() {
        return *s.begin();
    }
};