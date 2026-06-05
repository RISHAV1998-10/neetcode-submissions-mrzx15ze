class Solution {
public:
    void dfs(int idx, unordered_map<int, vector<int>>& adj, vector<bool>& vis){
        vis[idx] = true;
        for(int i: adj[idx])
            if(!vis[i])
                dfs(i, adj, vis);

        // return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1)
            return false;

        unordered_map<int, vector<int>> adj;
        for(auto e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n, false);
        dfs(0, adj, vis);
        for(int i=0; i<n; i++)
            if(!vis[i])
                return false;

        return true;    
    }
};
