class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l=0, r=0;
        int len=0, maxf=0;
        vector<int> freq(26, 0);

        // for(char c: freq)
        //     freq[c]++;

        while(r<n){
            freq[s[r]-'A']++;
            maxf=max(maxf, freq[s[r]-'A']);

            while(r-l+1 - maxf > k){
                freq[s[l]-'A']--;
                l++;
            }

            len=max(len, r-l+1);
            r++;
        }

        return len;
    }
};
