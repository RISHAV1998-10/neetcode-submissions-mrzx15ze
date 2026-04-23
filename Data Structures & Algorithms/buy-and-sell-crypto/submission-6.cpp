class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n = prices.size();
       int l=0, r=1;
       int res = 0;
       while(r<n){
            if(prices[r]>prices[l]){
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
