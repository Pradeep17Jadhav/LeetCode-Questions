class MyCalendar {
public:
    unordered_map<int, int> mp;
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        for(auto &[f, s] : mp) {
            if(!(start >= s || end <= f))
                return false;
        }
        mp[start] = end;
        return true;
    }
};