class Solution {
public:
    int time(vector<int>& piles, int rate){
        int t=0;
        for(int p:piles){
            t+=ceil(p/(double)rate);
        }
        return t;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxR = *max_element(piles.begin(), piles.end());
        int l=1, r=maxR, res=maxR;
        cout<<"max Rate: "<<maxR<<endl;
        while(l<=r){
            int rate=(l+r)/2;
            int t=time(piles, rate);
            cout<<"time: "<<t<<" ";
            if(t<=h){
                if(res>rate)
                    res=rate;
                r=rate-1;
            }
            else
                l=rate+1;
        }

        return res;
    }
};
