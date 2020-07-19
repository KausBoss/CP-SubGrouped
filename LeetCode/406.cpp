class Solution {
public:
	struct comp{
		bool operator()(vector<int> a, vector<int> b){
			if(a[0] == b[0]){
        		return a[1] > b[1];
        	}
        	return a[0] < b[0];
		}
	};
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        priority_queue<vector<int>, vector<vector<int>>, comp> p;
        for(auto x:people){
        	p.push(x);
        }
        vector<vector<int>> ans;
        while(!p.empty()){
        	ans.insert(ans.begin() + p.top()[1], p.top());
        	p.pop();
        }
        return ans;
    }
};