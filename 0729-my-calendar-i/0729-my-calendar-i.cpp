class MyCalendar {
public:
    vector<pair<int,int>> events;

    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        for(auto it : events) {
            int start = it.first;
            int end = it.second;

            if(max(start, startTime) < min(end, endTime)) {
                return false;
            }
        }

        events.push_back({startTime, endTime});
        return true;
    }
};
