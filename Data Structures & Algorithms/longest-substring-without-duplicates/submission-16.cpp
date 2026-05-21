class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, r=0, n=s.size();
        int res=0;
        unordered_set<char> uset;

        while(r<n){
            while(uset.count(s[r]) > 0){
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
