class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int n = s.size();
        int maxf=0, res=0;
        int l=0,r=0;
        while(r<n){
            freq[s[r]]++;
            maxf= max(maxf, freq[s[r]]);

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
