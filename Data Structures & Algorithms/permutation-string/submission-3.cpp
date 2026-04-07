class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();

        if(n1>n2)
            return false;

        vector<int> freq1(26, 0), freq2(26,0);
        for(char c: s1)
            freq1[c-'a']++;
        int l=0, r=0;
        while(r<n1){
            freq2[s2[r]-'a']++;
            r++;
        }

        if(freq1 == freq2)
            return true;

        while(r<n2){
            freq2[s2[r]-'a']++;
            freq2[s2[l]-'a']--;
            r++;
            l++;

            if(freq1 == freq2)
                return true;
        }

        return false;

    }
};
