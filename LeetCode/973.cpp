class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pair<int, int>> p;
        for(int i=0; i<points.size(); i++){
        	auto x = points[i];
        	p.push({(x[0]*x[0]) + (x[1]*x[1]), i});
        	if(p.size() > K){
        		p.pop();
        	}
        }
        vector<vector<int>> ans;
        while(!p.empty()){
        	ans.push_back(points[p.top().second]);
        	p.pop();
        }
        return ans;
    }
};