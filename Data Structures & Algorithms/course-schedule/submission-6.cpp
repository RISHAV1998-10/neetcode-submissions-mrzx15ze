class Solution {
public:
    bool isCycle(int idx, unordered_map<int, vector<int>>& preMap, vector<int> state){
        if(state[idx]==1)
            return true;

        if(state[idx]==2)
            return false;
        
        state[idx] = 1;
        
        for(int i: preMap[idx]){
            if(isCycle(i, preMap, state))
                return true;
        }

        state[idx]=2;

        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> preMap;

        for(auto& p: prerequisites)
            preMap[p[0]].push_back(p[1]);

        vector<int> state(numCourses, 0);

        for(int i=0; i<numCourses; i++){
            if(state[i]==0 && isCycle(i, preMap, state))
                return false;
        }

        return true;
    }
};
