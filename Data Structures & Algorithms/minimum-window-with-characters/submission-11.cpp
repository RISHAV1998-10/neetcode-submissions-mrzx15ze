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

        int cnt=0, l=0, len=INT_MAX, idx=-1;
        for(int r=0; r<ns; r++){
            if(freq.count(s[r])){
                freq[s[r]]--;

                if(freq[s[r]] >= 0)
                    cnt++;
            }

            while(cnt == nt){
                if(r-l+1 < len){
                    len = r-l+1;
                    idx=l;
                }

                if(freq.count(s[l])){
                    freq[s[l]]++;
                    if(freq[s[l]]>0)
                        cnt--;
                }
                l++;
            }
        }

        return idx==-1 ? "" : s.substr(idx, len);
    }
};
