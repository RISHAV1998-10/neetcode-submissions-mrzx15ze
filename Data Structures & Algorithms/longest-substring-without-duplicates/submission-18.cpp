class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> hash;
        int l=0, r=0, n=s.size();
        int len=0;
        while(r<n){
            while(hash.find(s[r])!=hash.end()){
                hash.erase(s[l]);
                l++;
            }

            len=max(len, r-l+1);
            hash.insert(s[r]);
            r++;
        }

        return len;
    }
};
