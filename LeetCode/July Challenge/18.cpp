class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> inDeg(n, 0);
        for(auto x:prerequisites){
        	inDeg[x[0]]++;
        }
        vector<vector<int>> adj(n);
        for(auto x:prerequisites){
        	adj[x[1]].push_back(x[0]);
        }
        queue<int> q;
        for(int i=0; i<n; i++){
        	if(inDeg[i] == 0){
        		q.push(i);
        	}
        }
        vector<int> ans;

        while(!q.empty()){
        	int u=q.front();
        	q.pop();
        	ans.push_back(u);
        	for(auto v:adj[u]){
        		inDeg[v]--;
        		if(inDeg[v] == 0){
        			q.push(v);
        		}
        	}
        }
        vector<int> em;
        return (ans.size()==n) ? ans : em;
    }
};