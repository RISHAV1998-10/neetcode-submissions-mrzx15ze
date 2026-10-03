class Solution {
public: 
    int time(vector<int>& piles, int k){
        int t = 0;
        for (int p : piles) {
            t += (p + k - 1) / k;
        }

        return t;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxele = *max_element(piles.begin(), piles.end());
        int l=1, r=maxele, ans=maxele;
        while(l<=r){
            int k = l+(r-l)/2;
            int t = time(piles, k);

            if(t<=h){
                ans=min(ans, k);
                r=k-1;
            }
            else{
                l=k+1;
            }
        }

        return ans;

    }
};
