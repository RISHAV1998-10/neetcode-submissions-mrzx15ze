class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<pair<int,double>> time;
        for(int i=0; i<n; i++){
            double ti = (target-position[i])/(double)speed[i];
            time.push_back({position[i], ti});
        }

        sort(time.begin(), time.end());

        int cnt=0;
        double maxr = 1e-9;
        for(int i=n-1; i>=0; i--){
            double t = time[i].second;
            if(t>maxr){
                cnt++;
                maxr=t;
            }
        }
        
        return cnt;
    }
};
