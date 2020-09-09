int maxHist(vector<int> h){
	int n = h.size(), ans=0;
	stack<int> s;
	for(int i=0; i<n;){
    	if(!s.empty() && h[i] <= h[s.top()]){
    		int height = h[s.top()];
    		s.pop();

    		if(s.empty()){
    			ans = max(ans, height*i);
    		}
    		else{
    			ans = max(ans, height*(i-s.top()-1));
    		}
    	}
    	else{
    		s.push(i++);
    	}
    }
    while(!s.empty()){
    	int height = h[s.top()];
		s.pop();

		if(s.empty()){
			ans = max(ans, height * n);
		}
		else{
			ans = max(ans, height * (n - s.top()-1));
		}
    }
    return ans;
}
int maxArea(int M[MAX][MAX], int n, int m) {
	vector<int> h(m, 0);
	int ans =0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(M[i][j]){ h[j] += M[i][j];}
			else{h[j]=0;}
		}
		ans = max(ans, maxHist(h));
	}
	return ans;
}
