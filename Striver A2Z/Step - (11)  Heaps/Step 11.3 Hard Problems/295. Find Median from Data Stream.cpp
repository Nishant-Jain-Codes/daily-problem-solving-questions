class MedianFinder {
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

public:
    MedianFinder() {}

    void addNum(int num) {
        if (left.empty())
            left.push(num);
        else if (left.top() < num)
            right.push(num);
        else {
            left.push(num);
        }
        if (std::abs(int(left.size() - right.size())) > 1) {
            if (left.size() > right.size()) {
                right.push(left.top());
                left.pop();
            } else {
                left.push(right.top());
                right.pop();
            }
        }
    }

    double findMedian() {
        if (left.size() == right.size())
            return (left.top() + right.top()) / 2.0;
        if(left.size()>right.size())
            return left.top();
        else 
            return right.top();
    }
};


