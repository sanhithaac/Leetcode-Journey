class MyCalendarTwo {
public:
    vector<pair<int,int>> bookings;
    vector<pair<int,int>> overlaps;

    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {

        for(auto &p : overlaps) {
            if(max(start, p.first) < min(end, p.second)) {
                return false;
            }
        }

        for(auto &p : bookings) {
            int s = max(start, p.first);
            int e = min(end, p.second);

            if(s < e) {
                overlaps.push_back({s, e});
            }
        }

        bookings.push_back({start, end});

        return true;
    }
};