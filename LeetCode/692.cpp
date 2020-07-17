class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> m;
        for(auto x:words){
        	m[x]++;
        }
        priority_queue<pair<int,string>> p;
        for(auto x:m){
        	p.push({-x.second, x.first});
        	if(p.size() > k){
        		p.pop();
        	}
        }
        vector<string> ans;
        while(!p.empty()){
        	ans.push_back(p.top().second);
        	p.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};