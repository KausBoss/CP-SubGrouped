class Solution {
public:
	int n, m;
	int movex[4] = {0, 0, 1, -1};
	int movey[4] = {1, -1, 0, 0};
	bool dfs(int i, int j, int k, vector<vector<char>> board, vector<vector<bool>> visited, string s){
		//base case
		visited[i][j] = 1;
        //recursive case
        if(board[i][j] == s[k] && k==s.length()-1){return 1;}
		for(int l=0; l<4; l++){
            if(i+movex[l] >=0 && i+movex[l]<n && j+movey[l]>=0 && j+movey[l]<m &&
               visited[i+movex[l]][j+movey[l]]==0 && 
               board[i+movex[l]][j+movey[l]] == s[k+1]){
			    bool next = dfs(i+movex[l], j+movey[l], k+1, board, visited, s);
			    if(next){return 1;} 
            }
		}
		visited[i][j]=0;
		return 0;

	}
    bool exist(vector<vector<char>>& board, string s) {
        n = board.size();
        m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, 0));
        for(int i=0; i<n; i++){
        	for(int j=0; j<m; j++){
        		if(board[i][j] == s[0]){
        			bool possible = dfs(i, j, 0, board, visited, s);
        			if(possible){
        				return 1;
        			}
        		}
        	}
        }
        return 0;
    }
};