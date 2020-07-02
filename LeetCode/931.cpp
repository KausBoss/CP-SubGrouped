class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n=A.size();
        if(n == 1){return A[0][0];}
        vector<vector<int>> dp=A;

        for(int i=1; i<n; i++){
        	for(int j=0; j<n; j++){
        		if(j == 0){
        			dp[i][j] = A[i][j] + min(dp[i-1][j], dp[i-1][j+1]);
        		}
        		else if(j == n-1){
        			dp[i][j] = A[i][j] + min(dp[i-1][j-1], dp[i-1][j]);
        		}
        		else{
        			dp[i][j] = A[i][j] + min(dp[i-1][j-1], min(dp[i-1][j], dp[i-1][j+1]));
        		}
        	}
        }
        int ans=dp[n-1][0];
        for(int i=1; i<n; i++){
        	ans = min(ans, dp[n-1][i]);
        }
        return ans;
    }
};