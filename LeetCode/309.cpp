/*
dp[len][2]

case 1. We have a stock on day i, dp[i][1]
    - I bought it today
      dp[i-2][0] - price[i]
    - I am carry forwarding
      dp[i-1][1]

case 2. We have no stocks on the day i, dp[i][0]
    - I sold it today
      dp[i-1][1] + price[i]
    - I am carry forwarding emptiness
      dp[i-1][0]

*/

class Solution {
public:
    int maxProfit(vector<int>& P) {
        int n = P.size();
        if(n <= 1){
            return 0;
        }
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][1] = -P[0];
        dp[1][0] = max(0, P[1] - P[0]);
        dp[1][1] = max(-P[1], -P[0]);

        for(int i=2; i<n; i++){
            dp[i][1] = max(dp[i-2][0] - P[i], dp[i-1][1]);

            dp[i][0] = max(dp[i-1][1] + P[i], dp[i-1][0]);
        }
        return max(dp[n-1][1], dp[n-1][0]);
    }
};