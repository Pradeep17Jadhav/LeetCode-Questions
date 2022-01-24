class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        // return destCity1(paths);
        return destCity2(paths);
    }
    
    string destCity1(vector<vector<string>>& paths) {
        unordered_set<string>cities;
        for(auto &path: paths)
            cities.insert(path[0]);
        
        for(auto &path: paths)
            if(cities.find(path[1]) == cities.end()) return path[1];
        return "";
    }
    
    string destCity2(vector<vector<string>>& paths) {
        unordered_map<string, int>cities;
        for(auto &path: paths)
        {
            cities[path[0]] += 1;
            cities[path[1]] += 0;
        }
        
        for(auto &[k, v]: cities)
            if(v == 0) return k;
        return "";
    }
};