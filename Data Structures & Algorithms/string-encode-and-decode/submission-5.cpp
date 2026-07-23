class Solution {
public:

    string encode(vector<string>& strs) {
        string str = "";
        for(const auto& s: strs){
            string n = to_string(s.size());
            str+=n+"#"+s;
        }

        return str;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i=0;
        while(i<s.size()){
            int n=0;
            while(s[i]!='#' && isdigit(s[i])){
                n=n*10+(s[i]-'0');
                i++;
            }
            res.push_back(s.substr(i+1, n));
            i=i+1+n;
        }

        return res;
    }
};
