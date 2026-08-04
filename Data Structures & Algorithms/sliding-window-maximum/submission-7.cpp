class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> res(n-k+1, 0);
        int l=0;
        for(int r=0; r<n; r++){
            while(!dq.empty() && nums[r]>nums[dq.back()])
                dq.pop_back();
            dq.push_back(r);
            while(l>dq.front())
                dq.pop_front();
            if(r>=k-1){
                res[l]=nums[dq.front()];
                l++;
            }
        }

        return res;
    }
};
