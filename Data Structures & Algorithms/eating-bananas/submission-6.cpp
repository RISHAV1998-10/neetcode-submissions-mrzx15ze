class Solution {
public:
    int timeTaken(vector<int>& piles, int r){
        double sum=0;
        for(int n: piles)
            sum+=ceil((double)n/r);

        return (int)sum;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int l=1, r=*max_element(piles.begin(), piles.end());
        int k=r;
        while(l<=r){
            int mid = (l+r)/2;
            int t = timeTaken(piles, mid);
            if(t>h)
                l=mid+1;
            else{
                k=min(k, mid);
                r=mid-1;
            }

        }

        return k;
    }
};
