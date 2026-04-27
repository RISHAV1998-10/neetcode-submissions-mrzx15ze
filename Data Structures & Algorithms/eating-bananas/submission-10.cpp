class Solution {
public:
    int time(vector<int>& piles, int k){
        double t=0.0;
        for(int p:piles)
            t+=ceil((double)p/k);

        return (int)t;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int val = *max_element(piles.begin(), piles.end());
        int l=1, r=val;
        int k=0;
        while(l<=r){
            int mid = (l+r)/2;
            int t=time(piles, mid);
            if(t<=h){
                k=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }

        return k;
    }
};
