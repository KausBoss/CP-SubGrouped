vector <int> dijkstra(vector<vector<int>> g, int src, int V){
    vector<int> dist(V, INT_MAX);
    set<pair<int, int>> s;
    s.insert({0, src});
    dist[src] = 0;
    while(!s.empty()){
    	auto p = *s.begin();
    	s.erase(p);
    	int node = p.second;
    	int nodeWeight = p.first;

    	for(int i=0; i<g[node].size(); i++){
    	    if(g[node][i]==0){continue;}
    		if(dist[i] > nodeWeight + g[node][i]){
    			auto ptr = s.find({dist[i], i});
    			if(ptr != s.end()){
    				s.erase(ptr);
    			}
    			dist[i] = nodeWeight + g[node][i];
    			s.insert({dist[i], i});
    		}
    	}
    }
    return dist;
}