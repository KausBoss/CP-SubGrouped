class StockSpanner {
	stack<pair<int,int>> s;
	int id;
public:
    StockSpanner() {
        id=0;
    }
    
    int next(int price) {
        while(!s.empty() && price >= s.top().first){
        	s.pop();
        }
        int val = (s.empty()) ? id+1 : (id-s.top().second);
        s.push({price, id});
        id++;
        return val;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */