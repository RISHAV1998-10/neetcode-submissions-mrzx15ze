class Solution {
public:
    string minWindow(string s, string t) {
        int ns = s.size();
        int nt = t.size();

        if(nt > ns)
            return "";

        unordered_map<char, int> freq;
        for(char c: t)
            freq[c]++;

        int startIdx = -1, len = INT_MAX;
        int l=0, r=0, cnt = 0;

        while(r<ns){
            if(freq.find(s[r])!=freq.end()){
                freq[s[r]]--;

                if(freq[s[r]]>=0)
                    cnt++;
            }

            while(cnt == nt){
                if(len > r-l+1){
                    startIdx = l;
                    len = r-l+1;
                }

                if(freq.find(s[l])!=freq.end()){
                    freq[s[l]]++;
                    if(freq[s[l]] > 0)
                        cnt--;
                }

                l++;
            }

            r++;
        }

        return startIdx == -1 ? "" : s.substr(startIdx, len);
    }
};
