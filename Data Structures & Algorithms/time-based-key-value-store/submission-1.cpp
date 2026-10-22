class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> tm;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        tm[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        int l = 0, r = tm[key].size() - 1;
        int m = 0;
        int prev = -1;
        while(l<=r){
            m = l+ (r-l)/2;
            if(tm[key][m].first == timestamp) return tm[key][m].second;
            else if(tm[key][m].first > timestamp) r = m-1;
            else{
                prev = m;
                l = m+1; 
            } 
        }

        if(prev > -1) return tm[key][prev].second;
        return "";
    }
};
