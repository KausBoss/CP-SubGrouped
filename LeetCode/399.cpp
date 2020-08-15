class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& e, vector<double>& v, vector<vector<string>>& q) {
        map<string, vector<pair<string, double>>> g;

        for(int i=0; i<e.size(); i++){
        	g[e[i][0]].push_back({e[i][1], v[i]});
        	g[e[i][1]].push_back({e[i][0], 1/v[i]});
        }
        vector<double> res;
        for(int i=0; i<q.size(); i++){
        	string s = q[i][0];
        	string d = q[i][1];
        	map<string, bool> v;
        	double ans=-1;
        	if(g.find(s)!=g.end()){
        		dfs(s, d, g, v, ans, 1.0);
        	}
        	res.push_back(ans);
        }
        return res;
    }
    void dfs(string s, string d, map<string, vector<pair<string, double>>> g,
    	map<string, bool> visited, double &ans, double temp){
    	if(visited.count(s) == 1){
    		return;
    	}
    	visited[s] = 1;
    	if(s == d){
    		ans = temp;
    		return;
    	}
    	for(auto child:g[s]){
    		dfs(child.first, d, g, visited, ans, temp*child.second);
    	}
    }
};