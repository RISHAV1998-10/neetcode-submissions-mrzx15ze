class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int len = tasks.size();
        int maxF = 0;
        int maxCnt = 0;
        unordered_map<int, int> freq;

        for(int i=0; i<tasks.size(); i++)
            freq[tasks[i]]++;
        
        for(auto [t, f] : freq){
            if(f>maxF){
                maxF=f;
                maxCnt = 0;
            }
            if(maxF==f)
                maxCnt++;
        }

        int numOfSeq = maxF-1;
        int seqLen = n-maxCnt+1;
        int nonMaxTask = len - maxCnt*maxF;
        int idleTime = numOfSeq * seqLen - nonMaxTask;

        return idleTime>0 ? len+idleTime : len;

    }
};
