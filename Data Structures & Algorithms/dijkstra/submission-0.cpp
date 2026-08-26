class Solution {
public:
    unordered_map<int, int> shortestPath(int n, vector<vector<int>>& edges, int src) {
        unordered_map<int, int> ans;
        unordered_map<int, bool> visited;
        bool found = true;
        int current = src;
        for(int i = 0; i < n; i++) {
            ans[i] = -1;
            visited[i] = false;
        }
        ans[src] = 0;
        
        while(found) {
            found = false;
            int minDist = -1;
            for(auto it = edges.begin(); it != edges.end(); it++) {
                if (it->at(0) == current) {
                    ans[it -> at(1)] = ans[it -> at(1)] == -1 ? ans[current] + it -> at(2) : min(ans[it -> at(1)], ans[current] + it -> at(2));
                }
            }
            visited[current] = true;
            for(int i = 0; i < n; i++) {
                if(visited[i] || ans[i] == -1) continue;
                found = true;
                if(ans[i] < minDist || minDist == -1) {
                    current = i;
                    minDist = ans[i];
                }
            }
        }
        
        return ans;
    }
};
