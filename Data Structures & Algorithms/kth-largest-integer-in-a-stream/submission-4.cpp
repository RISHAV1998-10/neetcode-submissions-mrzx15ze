class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int cap;
    KthLargest(int k, vector<int>& nums) {
        cap = k;
        for(int n: nums){
            pq.push(n);
            if(pq.size()>k)
                pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>cap)
            pq.pop();


        return pq.top();

    }
};
