class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> hash;

        for(int x: nums){
            if(hash.find(x)!=hash.end())
                return true;

            hash.insert(x);
        }

        return false;
    }
};