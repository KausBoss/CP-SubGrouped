class Solution {
public:
    int maximalSquare(vector<vector<char>>& m) {
        if(m.size() == 0){return 0;}
        int n = m.size(), b= m[0].size(), ans=0;
        vector<vector<int>> dp(n, vector<int>(b, 0));

        for(int i=0; i<n; i++){
        	for(int j=0; j<b; j++){
        		dp[i][j] = m[i][j] - '0';
        		if(dp[i][j]){
        			if(i>0 && j>0 && dp[i-1][j] && dp[i-1][j-1] && dp[i][j-1]){
        				dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
        			}
        		}
        		ans = max(ans , dp[i][j]);
        	}
        }
        return ans*ans;
    }
};