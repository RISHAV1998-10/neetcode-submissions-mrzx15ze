class MedianFinder {
public:
    priority_queue<int> maxH;
    priority_queue<int, vector<int>, greater<>> minH;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxH.push(num);
        if(!minH.empty() && (maxH.top()>minH.top())){
            minH.push(maxH.top());
            maxH.pop();
        }
        if(minH.size() > maxH.size() + 1){
            maxH.push(minH.top());
            minH.pop();
        }
        if(maxH.size() > minH.size() + 1){
            minH.push(maxH.top());
            maxH.pop();
        }

    }
    
    double findMedian() {
        if(maxH.size()==minH.size()){
            return ((double)(minH.top()+maxH.top()))/2;
        }
        else if(minH.size()>maxH.size())
            return minH.top();
        else 
            return maxH.top();
    }
};
