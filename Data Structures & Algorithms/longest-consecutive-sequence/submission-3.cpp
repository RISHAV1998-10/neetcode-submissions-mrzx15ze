class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> mp(nums.begin(), nums.end());
        int res=0;
        int l = 0;
        for(int num:mp){
            if(mp.find(num-1)==mp.end()){
                int len=1;
                while(mp.find(num++)!=mp.end())
                    len++;

                res=max(res, len-1);
            }
        }

        return res;
    }
};
