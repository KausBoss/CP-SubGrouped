/*
Case 1: I have stock on day i Represented by dp[i][1], select max of the below:
	-case1: I bought it today
			dp[i][1] = dp[i-1][0] - p[i] - fee
	-case2: I am carrying pre-bought stock> Doing nothing today.
			dp[i][1] = dp[i-1][1]

Case 2: I dont have stock on the day i, Represented by dp[i][0], select the maximum of the below:
	-case1: I sold it today
			dp[i][0] = dp[i][1] + p[i]
	-case2: I sold a stock at some previous day. Doing nothing today
			dp[i][0] = dp[i-1][0] 
*/

class Solution {
public:
    int maxProfit(vector<int>& P, int f) {
        int n = P.size();
        if(n <= 1){
            return 0;
        }
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][1] = -P[0] - f;

        for(int i=1; i<n; i++){
            dp[i][1] = max(dp[i-1][0] - P[i] - f, dp[i-1][1]);
            dp[i][0] = max(dp[i-1][1] + P[i], dp[i-1][0]);
        }
        return max(dp[n-1][1], dp[n-1][0]);
    }
}; 