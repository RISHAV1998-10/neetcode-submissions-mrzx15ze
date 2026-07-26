class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> hash;
        int l=0, r=0, n=s.size();
        int len=0;
        while(r<n){
            if(hash.find(s[r])==hash.end()){
                hash.insert(s[r]);
                r++;
            }
            else{
                hash.erase(s[l]);
                l++;
            }
            len=max(len, r-l);
        }

        return len; 
    }
};
