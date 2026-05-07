class Solution {
public:
    int time(vector<int>& piles, int k){
        double t = 0.0;
        for(int p:piles){
            t+=ceil((double)p/k);
        }

        return (int)t;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxi = *max_element(piles.begin(), piles.end());
        int l=1, r=maxi;
        int res=maxi+1;
        while(l<=r){
            int k=(l+r)/2;
            int t=time(piles, k);
            
            if(t<=h){
                res=k;
                r=k-1;
            }
            else{
                l=k+1;
            }
        }
        return res;
    }
};
