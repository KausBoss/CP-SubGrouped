class Solution {

	class worker{
		public:
		int quality;
		int wage;
		double ratio;
		worker(){}
		worker(int quality, int wage){
			this->quality=quality;
			this->wage=wage;
			ratio=(double)wage/quality;
		}
	};
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
    	int n=quality.size();
    	worker *w = new worker[n];

    	for(int i=0; i<n; i++){
    		w[i] = worker(quality[i], wage[i]);
    	}

    	sort(w, w+n, [=](worker a, worker b){
    		return a.ratio < b.ratio;
    	});

    	int tot=0;
        double ans=INT_MAX;
    	priority_queue<int> p;
    	for(int i=0; i<n; i++){
    		if(p.size() < K){
    			tot += w[i].quality;
    			p.push(w[i].quality);
    		}
    		else{
    			ans = min(ans, tot*w[i-1].ratio);
    			tot -= p.top();
    			p.pop();
    			tot += w[i].quality;
    			p.push(w[i].quality);	
    		}
    	}
    	ans = min(ans, tot*w[n-1].ratio);
    	return ans;
    }
};