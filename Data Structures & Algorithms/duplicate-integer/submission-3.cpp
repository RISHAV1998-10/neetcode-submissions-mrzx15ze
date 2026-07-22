class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> hash;
        for(int x: nums){
            if(hash.count(x)>0)
                return true;
            hash.insert(x);
        }

        return false;
    }
};