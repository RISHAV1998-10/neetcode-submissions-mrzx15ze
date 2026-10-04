class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l=0, r=n-1;

        while(l<=r){
            int m = l+(r-l)/2;
            if(target == nums[m])
                return m;
            else{                
                //right sorted
                if(nums[m]<=nums[r]){
                    if(target>nums[m] && target<=nums[r])
                        l=m+1;
                    else
                        r=m-1;
                }
                //left sorted
                else{
                    if(target>=nums[l] && target<nums[m])
                        r=m-1;
                    else
                        l=m+1;
                }
            }
        }

        return -1;
    }
};
