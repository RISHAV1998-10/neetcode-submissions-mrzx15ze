class Solution {
public:
    bool dfs(int idx, int parent, unordered_map<int, vector<int>>& adj,  vector<int>& vis){
        vis[idx] = true;
        for(int i: adj[idx]){
            if(!vis[i]){
                if(dfs(i, idx, adj, vis))
                    return true;
            }
            else if(i!=parent)
                return true;
        }
        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() > n-1)
            return false;

        unordered_map<int, vector<int>> adj;
        for(auto& e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(n, false);

        dfs(0, -1, adj, vis);

        for(bool v: vis)
            if(!v)
                return false;
        
        return true;
    }
};
