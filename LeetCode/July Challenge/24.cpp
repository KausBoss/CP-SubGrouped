class Solution {
public:
	vector<vector<int>> ans;
	void DFS(int curr, vector<vector<int>>& graph, vector<int> journey){
		journey.push_back(curr);
		if(curr == graph.size() - 1){ans.push_back(journey);return;}
		for(auto x:graph[curr]){
			DFS(x, graph, journey);
		}
		return;
	}
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        map<int, bool> visited;
        DFS(0, graph, visited, path);
        return ans;
    }
};