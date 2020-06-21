class Solution {
public:
    int minRefuelStops(int n, int startFuel, vector<vector<int>>& st) {
        int i =0 , pos = startFuel, ans = 0;
        int m = st.size();
        priority_queue<int> pq;
        while(pos < n){
        	while(i < m && st[i][0] <= pos){
        		pq.push(st[i++][1]);
        	}

        	if(pq.empty()){return -1;}

        	pos += pq.top();
        	ans++;
        	pq.pop();

        	if(pos >= n){
        		return ans;
        	}
        }
        return 0;
    }
};