class Solution {
public:
    void dfs(int idx, int parent,  unordered_map<int, vector<int>>& adj, vector<bool>& vis){
        vis[idx]=true;
        for(int i: adj[idx]){
            if(!vis[i])
                dfs(i, idx, adj, vis);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;

        for(auto& e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n, false);
        int cnt=0;
        for(int i=0; i<n; i++)
            if(!vis[i]){
                dfs(i, -1, adj, vis);
                cnt++;
            }
        return cnt;
    }
};
