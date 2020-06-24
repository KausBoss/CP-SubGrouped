class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        vector<int> dp(amount + 1, INT_MAX - 2);
        dp[0] = 0;
        for(int i=1; i <= amount; i++){
        	for(auto x:coins){
        		if(x <= i){
        			dp[i] = min(dp[i], 1 + dp[i - x]);
        		}
        	}
        }

        return dp[amount] > 100000 ? -1 : dp[amount];
    }
};