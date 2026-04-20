class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int heapSize;

    KthLargest(int k, vector<int>& nums) {
        heapSize=k;
        for(int num: nums){
            pq.push(num);
            if(pq.size()>k)
                pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>heapSize)
            pq.pop();

        return pq.top();
    }
};
