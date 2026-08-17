class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> pq;
        vector<int> res(n-k+1);
        int l=0;
        for(int r=0; r<n; r++){
            while(!pq.empty() && nums[r]>=nums[pq.back()])
                pq.pop_back();

            while(!pq.empty() && pq.front()<l)
                pq.pop_front();

            pq.push_back(r);

            if(r>=k-1){
                res[l]=nums[pq.front()];
                l++;
            }            
        }

        return res;
    }
};
