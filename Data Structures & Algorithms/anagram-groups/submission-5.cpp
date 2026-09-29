class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;

        for(string s : strs){
            string temp = s;
            sort(temp.begin(), temp.end());
            hash[temp].push_back(s);
        }

        vector<vector<string>> res;

        for(auto it=hash.begin(); it!=hash.end(); it++){
            res.push_back(it->second);
        }

        return res;
    }
};
