class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int l=0,r=0;
        unordered_set<char> uset;
        int len=0;
        while(r<n){
            while(uset.find(s[r])!=uset.end()){
                uset.erase(s[l]);
                l++;
            }
            len=max(len, r-l+1);
            uset.insert(s[r]);
            r++;
            
        }

        return len;
    }
};
