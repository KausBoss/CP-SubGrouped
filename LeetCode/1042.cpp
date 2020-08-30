class Solution {
public:
    vector<list<int>> g;
    vector<bool> visited;
    vector<int> ans;
    void dfs(int node){
        visited[node]=1;
        bool col[5] = {0, 1, 1, 1, 1};
        for(auto child:g[node]){
            if(ans[child] != 0){
                col[ans[child]]=0;
            }
        }
        for(int i=1; i<=4; i++){
            if(col[i]){
                ans[node] = i;
                break;
            }
        }
        for(auto child:g[node]){
            if(!visited[child]){
                dfs(child);
            }
        }
    }
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        g.resize(N);
        visited = vector<bool>(N, 0);
        ans = vector<int>(N, 0);
        for(auto x:paths){
            g[x[0]-1].push_back(x[1]-1);
            g[x[1]-1].push_back(x[0]-1);
        }
        for(int i=0; i<N; i++){
            if(!visited[i]){
                dfs(i);
            }
        }
        return ans;
    }
};