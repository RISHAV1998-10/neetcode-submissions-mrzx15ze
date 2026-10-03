class Solution {
public:
    double time(int dis, int sp){
        return ((double)dis)/sp;
    }
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        vector<pair<int, double>> times;
        int n = position.size();
        for(int i=0; i<n; i++){
            double t = time(target-position[i], speed[i]);
            times.push_back({-position[i], t});
        }

        sort(times.begin(), times.end());

        double maxTime = 0.0, cnt=0;
        for(auto [d, t]: times){
            if(t>maxTime){
                cnt++;
                maxTime=t;
            }
        }

        return cnt;
    }
};
