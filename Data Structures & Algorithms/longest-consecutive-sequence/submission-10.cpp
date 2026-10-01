class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash(nums.begin(), nums.end());

        int maxlen = 0;
        for(int n : nums){
            if(hash.find(n-1)==hash.end()){
                int len=0;
                while(hash.find(n)!=hash.end()){
                    len++;
                    n++;
                }

                if(maxlen<len)
                    maxlen = len;
            }
        }

        return maxlen;
    }
};
