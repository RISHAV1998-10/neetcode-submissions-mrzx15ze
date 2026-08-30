class KthLargest {
public:
    priority_queue<int, vector<int>, greater<>> minHeap;
    int cap;
    KthLargest(int k, vector<int>& nums) {
        cap = k;
        for(int num : nums){
            minHeap.push(num);
            if(minHeap.size()>k)
                minHeap.pop();
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size()>cap)
            minHeap.pop();

        return minHeap.top();
    }
};
