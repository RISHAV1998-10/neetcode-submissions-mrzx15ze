class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> uset;
        int res=0;
        for(int num: nums)
            uset.insert(num);

        for(int i=0; i<n; i++){
            if(uset.find(nums[i]-1)==uset.end()){
                int temp = 0;
                int num = nums[i];
                while(uset.count(num)){
                    temp++;
                    num++;
                }

                res = max(temp, res);    
            }
        }

        return res;
    }
};
