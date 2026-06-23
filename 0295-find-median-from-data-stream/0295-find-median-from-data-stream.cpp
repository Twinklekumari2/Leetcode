class MedianFinder {
public:
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxheap.empty() || num <= maxheap.top()){
            maxheap.push(num);
        }
        else{
            minheap.push(num);
        }
        int sizeMin = minheap.size(), sizeMax = maxheap.size();
        if(sizeMin > sizeMax+1){
            int top = minheap.top();
            minheap.pop();
            maxheap.push(top);
        }
        if(sizeMax > sizeMin+1){
            int top = maxheap.top();
            maxheap.pop();
            minheap.push(top);
        }
    }
    
    double findMedian() {
        int sizeMin = minheap.size();
        int sizeMax = maxheap.size();
        double median = 0.0;
        if((sizeMin+sizeMax)%2==0){
            median = (minheap.top() + maxheap.top())/2.0;
        }else{
            median = sizeMin > sizeMax ? minheap.top() : maxheap.top();
        }
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */