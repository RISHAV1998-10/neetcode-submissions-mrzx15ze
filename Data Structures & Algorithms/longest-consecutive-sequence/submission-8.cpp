class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());

        int res = 0, len=1 ;
        for(int x: nums){
            if(s.find(x-1)==s.end()){
                len = 1;
                while(s.find(x+1)!=s.end()){
                    x++; 
                    len++;
                }
            }
            res = max(res, len);
            s.insert(x);
        }

        return res;
    }
};
