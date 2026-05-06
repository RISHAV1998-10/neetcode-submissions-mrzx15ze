class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;

        int maxf=0, len=0, l=0, r=0;

        while(r<s.size()){
            freq[s[r]]++;
            maxf=max(maxf, freq[s[r]]);

            while(r-l+1-maxf > k){
                freq[s[l]]--;
                l++;
            }
            len=max(len, r-l+1);
            r++;
        }

        return len;
    }
};
