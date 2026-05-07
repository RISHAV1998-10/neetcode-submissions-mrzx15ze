class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int l=0, r=0;
        int res=0;

        while(r<n){
            if(prices[l]<prices[r]){
                res=max(res, prices[r]-prices[l]);
            }
            else{
                l=r;
            }
            r++;
        }

        return res;
    }
};
