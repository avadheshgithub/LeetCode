class MedianFinder {
public:
    MedianFinder(){}
    
    priority_queue<int>hi;
    priority_queue<int,vector<int>,greater<int>>lo;

    void addNum(int num) {
        hi.push(num);

        lo.push(hi.top()); // balancing itself
        hi.pop();

        if(hi.size() < lo.size()){ // from one heap to another
            hi.push(lo.top());
            lo.pop();
        }
    }
    
    double findMedian() {
        return hi.size() > lo.size() ? hi.top() : (hi.top()+lo.top()) * 0.5;
    }
};
