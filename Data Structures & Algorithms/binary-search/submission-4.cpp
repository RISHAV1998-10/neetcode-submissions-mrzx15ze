class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l=0, r=n-1;

        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                r=r-1;
            else
                l=l+1;
        }

        return -1;
    }
};
