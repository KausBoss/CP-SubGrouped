int n, m;
int mx[8]={1, -1, 0, 0, -1, 1, 1, -1};
int my[8]={0, 0, 1, -1, 1, 1, -1, -1};

void dfs(int i, int j, vector<int> A[], vector<vector<bool>> &visited){
	visited[i][j] = 1;
	for(int k=0; k<8; k++){
		int ii = i+ mx[k];
		int jj = j+ my[k];
		if(ii<0 || jj<0 || ii>=n || jj>=m){continue;}
		if(A[ii][jj]==1 && visited[ii][jj]==0){
			dfs(ii, jj, A, visited);
		}
	}
}

int findIslands(vector<int> A[], int N, int M){
	int ans=0;
	n=N;m=M;
	vector<vector<bool>> visited(N, vector<bool>(M, 0));
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(A[i][j] == 1 && visited[i][j]==0){
				ans++;
				dfs(i, j, A, visited);
			}
		}
	}
	return ans;
}
