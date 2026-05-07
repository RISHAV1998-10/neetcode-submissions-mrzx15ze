class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l=0, r=0;
        unordered_set<int> uset;
        int res=0;

        while(r<n){
            while(uset.find(s[r])!=uset.end()){
                uset.erase(s[l]);
                l++;
            }
            uset.insert(s[r]);
            res=max(res, r-l+1);
            r++;
        }

        return res;
    }
};
