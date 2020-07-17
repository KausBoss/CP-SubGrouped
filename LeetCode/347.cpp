class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        for(auto x:nums){
        	m[x]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> p;
        for(auto x:m){
        	p.push({x.second,x.first});
        	if(p.size() > k){
        		p.pop();
        	}
        }
        vector<int> ans;
        while(!p.empty()){
        	ans.push_back(p.top().second);
        	p.pop();
        }
        return ans;
    }
};