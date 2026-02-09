class MedianFinder {
public:
    priority_queue<int> maxPQ; // max heap
    priority_queue<int, vector<int>, greater<int>> minPQ; // min heap

    MedianFinder() {}

    void addNum(int num) {
        maxPQ.push(num); // push into max

        minPQ.push(maxPQ.top()); // balance order
        maxPQ.pop();

        if (minPQ.size() > maxPQ.size()) { // balance size
            maxPQ.push(minPQ.top());
            minPQ.pop();
        }
    }

    double findMedian() {
        return (maxPQ.size() > minPQ.size()) ? maxPQ.top() : (maxPQ.top()+minPQ.top())/2.0;
    }
};
