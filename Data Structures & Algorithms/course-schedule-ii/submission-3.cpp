class Solution {
public:
    bool dfs(int idx, unordered_map<int, vector<int>>& adj, vector<int>& state, vector<int>& res){
        if(state[idx]==1)
            return true;

        if(state[idx]==2)
            return false;
        
        state[idx]=1;
        for(int i: adj[idx]){
            if(dfs(i, adj, state, res))
                return true;
        }
        state[idx]=2;
        res.push_back(idx);
        return false;
    }

    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;

        for(auto& p: prerequisites)
            adj[p[0]].push_back(p[1]);

        vector<int> state(n, 0);
        vector<int> res;

        for(int i=0; i<n; i++)
            if(state[i]==0 && dfs(i, adj, state, res))
                return {};

        return res;
    }
};
