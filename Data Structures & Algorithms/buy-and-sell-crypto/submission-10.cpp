class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprice = 0, minnum = prices[0];
        for(int p: prices){
            maxprice = max(maxprice, p-minnum);
            minnum = min(minnum, p);
        }

        return maxprice;
    }
};
