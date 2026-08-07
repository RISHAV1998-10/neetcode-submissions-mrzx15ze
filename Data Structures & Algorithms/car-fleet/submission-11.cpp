class Solution {
public:
    double time(int pos, int speed){
        return pos/(double)speed;
    }

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> times;

        for(int i=0; i<n; i++)
            times.push_back({position[i], time(target-position[i], speed[i])});
        
        double maxT = 1e-9;
        int cnt=0;

        sort(times.begin(), times.end());

        for(int i=n-1; i>=0; i--){
            double ti = times[i].second;
            if(ti > maxT){
                cnt++;
                maxT=ti;
            }
        }

        return cnt;
    }
};
