class Solution {
public:
	int n, m;
	vector<vector<bool>> visited;
	void dfs(int i, int j, vector<vector<int>>& image, int color){
		visited[i][j] = 1;
		int old = image[i][j];
		image[i][j] = color;
		if(i-1>=0 && image[i-1][j]==old && !visited[i-1][j]){
			dfs(i-1, j, image, color);
		}
		if(j-1>=0 && image[i][j-1]==old && !visited[i][j-1]){
			dfs(i, j-1, image, color);
		}
		if(i+1<n && image[i+1][j]==old && !visited[i+1][j]){
			dfs(i+1, j, image, color);
		}
		if(j+1<m && image[i][j+1]==old && !visited[1][j+1]){
			dfs(i, j+1, image, color);
		}
	}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        n = image.size();
        m = image[0].size();
        visited = vector<vector<bool>>(n, vector<bool>(m, 0));
        dfs(sr, sc, image, newColor);
        return image;
    }
};