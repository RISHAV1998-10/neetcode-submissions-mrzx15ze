class Solution {
public:
    string minWindow(string s, string t) {
        int nt=t.size(), ns=s.size();
        if(nt > ns)
            return "";

        unordered_map<char, int> freq;
        for(char c: t)
            freq[c]++;

        int l=0, r=0, cnt=0, idx=-1, len=ns+1;

        while(r<ns){
            char rc = s[r];
            if(freq.find(s[r])!=freq.end()){
                freq[rc]--;
                if(freq[rc]>=0)
                    cnt++;
            }

            while(cnt==nt){
                if(r-l+1<len){
                    idx=l;
                    len=r-l+1;
                }

                char lc=s[l];
                if(freq.find(lc)!=freq.end()){
                    freq[lc]++;
                    if(freq[lc]>0)
                        cnt--;                    
                }
                l++;
            }
            r++;
            cout<<endl;
        }

        return idx == -1 ? "" : s.substr(idx, len);
    }
};
