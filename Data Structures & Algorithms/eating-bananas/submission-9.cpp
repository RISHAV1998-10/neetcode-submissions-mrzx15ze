class Solution {
public:
    int timeTaken(vector<int>& piles, int k){
        double t=0.0;
        for(int p:piles)
            t+=ceil((double)p/k);

        return (int)t;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxPile = *max_element(piles.begin(), piles.end());

        int l=1, r=maxPile;
        int res=r;
        while(l<=r){
            int k=(l+r)/2;
            int t=timeTaken(piles, k);
            if(t<=h){
                res=min(res,k);
                r=k-1;
            }
            else{
                l=k+1;
            }
        }

        return res;
    }
};
