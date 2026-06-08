class Solution {
public:
    bool dfs(int idx, unordered_map<int, vector<int>>& adj, vector<int>& state){
        if(state[idx]==1)
            return true;

        if(state[idx]==2)
            return false;
        
        state[idx]=1;
        for(int i: adj[idx]){
            if(dfs(i, adj, state))
                return true;
        }
        state[idx]=2;
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;

        for(auto& p: prerequisites)
            adj[p[0]].push_back(p[1]);

        vector<int> state(n, 0);

        for(int i=0; i<n; i++)
            if(state[i]==0 && dfs(i, adj, state))
                return false;

        return true;
    }
};
