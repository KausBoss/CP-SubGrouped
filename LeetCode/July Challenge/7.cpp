class Solution {
public:
    int islandPerimeter(vector<vector<int>> g) {
        int peri=0, n=g.size(), m=g[0].size();
        for(int i=0; i<n; i++){
        	for(int j=0; j<m; j++){
        		if(g[i][j] == 1){
        			if(i == 0){peri++;}
        			if(i == n-1){peri++;}
        			if(j == 0){peri++;}
        			if(j == m-1){peri++;}
        			if(i != 0 && g[i-1][j] == 0){
        				peri++;
        			}
        			if(j != 0 && g[i][j-1] == 0){
        				peri++;
        			}
        			if(i != n-1 && g[i+1][j] == 0){
        				peri++;
        			}
        			if(j != m-1 && g[i][j+1] == 0){
        				peri++;
        			}
        		}
        	}
        }
        return peri;
    }
};