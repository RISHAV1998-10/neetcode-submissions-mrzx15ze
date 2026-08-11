class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> umap;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        umap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(umap.find(key) == umap.end())
            return "";
        auto& vec = umap[key];
        int l=0, r=vec.size()-1;
        string ans="";
        while(l<=r){
            int mid=(l+r)/2;
            if(vec[mid].first <= timestamp){
                ans=vec[mid].second;
                l=mid+1;
            }
            else
                r=mid-1;
        }

        return ans;
    }
};
