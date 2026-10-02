class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l=0, r=0, len=0;
        unordered_set<char> uset;
        while(r<n){
            while(uset.find(s[r])!=uset.end()){
                uset.erase(s[l]);
                l++;
            }
            uset.insert(s[r]);
            len=max(len, r-l+1);
            r++;
        }

        return len;
    }
};
