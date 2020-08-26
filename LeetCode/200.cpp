class Solution {
public:
	int n, m;
	void dfs(int i, int j, vector<vector<bool>>& visited, vector<vector<char>>& grid){
		visited[i][j] = 1;
		if(i+1<n && grid[i+1][j]=='1' && !visited[i+1][j]){
			dfs(i+1, j, visited, grid);
		}
		if(i-1>=0 && grid[i-1][j]=='1' && !visited[i-1][j]){
			dfs(i-1, j, visited, grid);
		}
		if(j+1<m && grid[i][j+1]=='1' && !visited[i][j+1]){
			dfs(i, j+1, visited, grid);
		}
		if(j-1>=0 && grid[i][j-1]=='1' && !visited[i][j-1]){
			dfs(i, j-1, visited, grid);
		}
	}
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ans=0
        vector<vector<bool>> visited(n, vector<bool>(m, 0));
        for(int i=0; i<n; i++){
        	for(int j=0; j<m; j++){
        		if(grid[i][j]=='1' && visited[i][j]==0){
        			ans++;
        			dfs(i, j , visited, grid);
        		}
        	}
        }
        return ans;
    }
};