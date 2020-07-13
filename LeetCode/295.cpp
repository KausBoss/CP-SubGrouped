class MedianFinder {
	priority_queue<int> mh;
	priority_queue<int, vector<int>, greater<int>> nh;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        mh.push(num);
        nh.push(mh.top());
        mh.pop();
        if(nh.size() - mh.size() > 1){
        	mh.push(nh.top());
        	nh.pop();
        }
    }
    
    double findMedian() {
        if(nh.size() > mh.size()){
        	return nh.top();
        }
        cout<<mh.top()<<" "<<nh.top()<<endl;
        double ret = mh.top() + nh.top();
        ret /=2;
        return ret;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */