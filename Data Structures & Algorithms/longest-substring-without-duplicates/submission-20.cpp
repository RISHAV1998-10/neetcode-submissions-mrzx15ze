class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256, -1);
        int l=0, res=0;

        for(int r=0; r<s.size(); r++){
            if(last[s[r]] >= l){
                l = last[s[r]]+1;
            }

            last[s[r]] = r;

            res= max(res, r-l+1);
        }

        return res;
    }
};
