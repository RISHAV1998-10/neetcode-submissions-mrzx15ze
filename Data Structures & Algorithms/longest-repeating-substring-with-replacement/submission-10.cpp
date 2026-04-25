class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_map<char, int> freq;
        int res=0, maxf = 0;
        int l=0, r=0;
        
        while(r<n){
            freq[s[r]]++;
            maxf=max(maxf, freq[s[r]]);
            
            while(r-l+1-maxf > k){
                freq[s[l]]--;
                l++;
            }
            res=max(res, r-l+1);
            r++;
        }

        return res;
    }
};
