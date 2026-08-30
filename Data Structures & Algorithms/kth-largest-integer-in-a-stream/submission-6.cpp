class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int cap;
    KthLargest(int k, vector<int>& nums) : cap(k) {
        for (int x : nums) {
            if (minHeap.size() < k) {
                minHeap.push(x);
            }
            else if (x > minHeap.top()) {
                minHeap.pop();
                minHeap.push(x);
            }
        }
    }
    
    int add(int val) {
        if (minHeap.size() < cap) {
            minHeap.push(val);
        } 
        else if (val > minHeap.top()) {
            minHeap.pop();
            minHeap.push(val);
        }

        return minHeap.top();
    }
};
