class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;

        int l=0, r=0, n=s.size();
        int maxLen=0, maxFreq=0;
        while(r<n){
            freq[s[r]]++;
            maxFreq=max(maxFreq, freq[s[r]]);

            while(r-l+1-maxFreq > k){
                freq[s[l]]--;
                l++;
            }

            maxLen=max(r-l+1, maxLen);
            r++;
        }

        return maxLen;

    }
};
