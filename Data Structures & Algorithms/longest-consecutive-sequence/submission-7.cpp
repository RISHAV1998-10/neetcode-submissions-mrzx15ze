class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uset(nums.begin(), nums.end());
        int res = 0;

        for(int num: nums){
            if(uset.find(num-1)==uset.end()){
                int len=0;
                while(uset.count(num)>0){
                    len++;
                    num++;
                }
                res=max(res, len);
            }
        }

        return res;

    }
};
