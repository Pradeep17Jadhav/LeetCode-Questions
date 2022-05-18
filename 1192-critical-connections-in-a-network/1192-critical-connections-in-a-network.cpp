class Solution {
public:
    int time = 1;
    vector<int> disc{0}, low{0};
    vector<vector<int>> res;
    unordered_map<int, vector<int>> edgeMap;
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        disc = vector<int>(n);
        low = vector<int>(n);
        for (auto conn: connections) 
        {
            edgeMap[conn[0]].push_back(conn[1]);
            edgeMap[conn[1]].push_back(conn[0]);
        }
        dfs(0, -1);
        return res;
    }
    
    void dfs(int curr, int prev) {
        disc[curr] = low[curr] = time++;
        for (int next : edgeMap[curr]) 
        {
            if(!disc[next]) 
            {
                dfs(next, curr);
                low[curr] = min(low[curr], low[next]);
            } 
            else if(next != prev)
            {
                low[curr] = min(low[curr], disc[next]);
            }

            if (low[next] > disc[curr]) 
                res.push_back({curr, next});
        }
    }
};