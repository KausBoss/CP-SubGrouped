//DAG to be abale to complete all courses
// Usage of topological sort to find a valid pattern
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<list<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);
        for(auto p:prerequisites){
        	adj[p[1]].push_back(p[0]);
        	inDegree[p[0]]++;
        }
        queue<int> q;
        vector<bool> visited(numCourses, 0);
        for(int i=0; i<numCourses; i++){
        	if(inDegree[i] == 0){
        		q.push(i);
        		visited[i] = 1;
        	}
        }
        int completed = 0;
        while(!q.empty()){
        	int cur = q.front();
        	completed++;
        	q.pop();
        	for(auto child:adj[cur]){
        		inDegree[child]--;
        		if(inDegree[child]==0 && visited[child]==0){
        			visited[child]=1;
        			q.push(child);
        		}
        	}
        }
        return completed==numCourses;
    }
};