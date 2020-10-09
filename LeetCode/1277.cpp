class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int ans=0;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0; i<n; i++){
        	for(int j=0; j<m; j++){
        		if(matrix[i][j] != 0){
        			ans++;
        			int val1= (i>0) ? matrix[i-1][j] : 0;
        			int val2= (j>0) ? matrix[i][j-1] : 0;
        			int val3= (i>0)&&(j>0) ? matrix[i-1][j-1] : 0;
        			matrix[i][j] = min(val1, min(val2, val3)) + 1;
        			ans += matrix[i][j] - 1;
        		}
        	}
        }
        return ans;
    }
};