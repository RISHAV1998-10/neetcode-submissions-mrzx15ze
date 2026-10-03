class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res(n-k+1, 0);
        deque<int> dq;
        int l=0, r=0;

        while(r<n){
            while(!dq.empty() && (nums[r] >= nums[dq.back()]))
                dq.pop_back();

            while(!dq.empty() && (l> dq.front()))
                dq.pop_front();
                
            dq.push_back(r);

            if(r+1>=k){
                res[l]=nums[dq.front()];
                l++;
            }

            r++;
        }

        return res;
    }
};
