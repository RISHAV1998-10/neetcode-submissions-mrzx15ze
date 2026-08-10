class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> umap;
public:
    TimeMap() {    }
    
    void set(string key, string value, int timestamp) {
        umap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = umap.find(key);
        if(it == umap.end())
            return "";
        
        auto &v = it->second;
        int l=0, r=v.size()-1;
        string ans="";

        while(l<=r){
            int mid=(l+r)/2;
            if(v[mid].first<=timestamp){
                ans=v[mid].second;
                l=mid+1;
            }
            else
                r=mid-1;
        }   

        return ans;
    }
};
