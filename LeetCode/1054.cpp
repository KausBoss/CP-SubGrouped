class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& b) {
        map<int,int> m;
        for(auto x:b){
        	m[x]++;
        }
        priority_queue<pair<int,int>> p;
        for(auto x:m){
        	p.push({x.second, x.first});
        }
        vector<int> ans;
        while(!p.empty()){
        	auto f = p.top();
        	p.pop();
        	if(!ans.empty() && ans.back() == f.second){
        		auto g = p.top();
        		p.pop();
        		ans.push_back(g.second);
        		if(g.first != 1){
        			g.first--;
        			p.push(g);
        		}
        		p.push(f);
        	}
        	else{
        		ans.push_back(f.second);
        		if(f.first != 1){
        			f.first--;
        			p.push(f);
        		}
        	}
        }
        return ans;
    }
};