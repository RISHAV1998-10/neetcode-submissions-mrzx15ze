class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int l=0, r=1, prof=0;
        while(r<n){
            if(prices[r]>prices[l]){
                prof=max(prof, prices[r]-prices[l]);
            }
            else{
                l=r;
            }
            r++;
        }

        return prof;
    }
};
