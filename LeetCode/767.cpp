class Solution {
public:
    string reorganizeString(string S) {
        map<char,int> m;
        for(auto x:S){
        	m[x]++;
        }
        priority_queue<pair<int, char>> p;
        for(auto x:m){
        	p.push({x.second, x.first});
        }
        if(p.top().first > ceil((float)S.length()/2)){return "";}
        string ans="";
        while(!p.empty()){
        	auto pr1 = p.top();
        	p.pop();
        	if(!ans.empty() && ans.back() == pr1.second){
        		if(p.empty()){
        			return "";
        		}
        		auto pr2 = p.top();
        		p.pop();
        		ans += pr2.second;
        		if(pr2.first > 1){
        			pr2.first--;
        			p.push(pr2);
        		}
        		p.push(pr1);
        	}
        	else{
        		ans += pr1.second;
        		if(pr1.first > 1){
        			pr1.first--;
        			p.push(pr1);
        		}
        	}
        }
        return ans;
    }
};