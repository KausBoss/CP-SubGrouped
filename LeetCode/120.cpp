class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
    	int n = t.size();
    	int *dp = new int[n];
    	dp[0] = t[0][0];
    	for(int i=1; i<n; i++){
    		for(int j=i; j>=0; j--){
    			if(j == i){
    				dp[j] = dp[j-1] + t[i][j];
    			}
    			else if(j == 0){
    				dp[j] = dp[j] + t[i][j];
    			}
    			else{
    				dp[j] = t[i][j] + min(dp[j], dp[j-1]);
    			}
    		}
    	}
    	int ans=dp[0];
    	for(int i=1; i<n; i++){
    		ans = min(ans, dp[i]);
    	}
    	return ans;
    }
};