class Solution {
public:
    bool dfs(int i, unordered_map<int, vector<int>>& preq, vector<int>& state){
        if(state[i]==1)
            return true;

        if(state[i]==2)
            return false;
        
        state[i]=1;
        for(int p: preq[i])
            if(dfs(p, preq, state))
                return true;
        
        state[i]=2;

        return false;
    }

    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> preq;

        for(auto& p: prerequisites)
            preq[p[0]].push_back(p[1]);

        vector<int> state(n, 0);

        for(int i=0; i<n; i++)
            if(state[i]==0 && dfs(i, preq, state))
                return false;

        return true;
    }
};
