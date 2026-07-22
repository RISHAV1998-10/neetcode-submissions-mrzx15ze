class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> h;
        for(string str : strs){
            string s = str;
            sort(s.begin(), s.end());
            h[s].push_back(str);
        }

        vector<vector<string>> res;
        for(auto& [key, vec]: h )
            res.push_back(vec);

        return res;
    }
};
