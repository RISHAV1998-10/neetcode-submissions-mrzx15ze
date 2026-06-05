class Solution {
public:
    bool dfs(int i, vector<vector<int>>& g, vector<int>& state){
        state[i] = 1;
        for(int v: g[i]){
            if(state[v]==1)
                return true;
            
            if(state[v]==0 && dfs(v, g, state))
                return true;
        }

        state[i] = 2;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);

        for(auto& p: prerequisites)
            g[p[0]].push_back(p[1]);

        vector<int> state(numCourses, 0);

        for(int i=0; i<numCourses; i++)
            if(state[i]==0 && dfs(i, g, state))
                return false;

        return true;
    }
};
