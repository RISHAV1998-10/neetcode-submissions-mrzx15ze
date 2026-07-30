class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int l=0, maxFreq=0, maxLen=0;

        for(int r=0; r<s.size(); r++){
            freq[s[r]]++;
            maxFreq = max(freq[s[r]], maxFreq);
            
            while(r-l+1-maxFreq > k){
                freq[s[l]]--;
                l++;
            }
            maxLen=max(maxLen, r-l+1);

        }

        return maxLen;
    }
};
