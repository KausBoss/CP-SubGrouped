class Solution {
public:
    int maxProfit(int k, vector<int>& p) {
    	if(k==0 || p.size() <= 1){return 0;}
    	int n = p.size();
    	if(k >= p.size()/2){
    		int ans=0;
    		for(int i=1;i<n; i++){
    			if(p[i] > p[i-1]){
    				ans += p[i]-p[i-1];
    			}
    		}
    		return ans;
    	}

    	vector<vector<int>> dp(min((n/2)+1, k+1), vector<int>(n, 0));

    	for(int i=1; i<dp.size(); i++){
    		for(int j=1; j<n; j++){
    			int ans=0;
    			for(int l=0; l<j; l++){
    				ans = max(ans, p[j]-p[l] + dp[i-1][l]);
    			}
    			dp[i][j] = max(ans, dp[i][j-1]);
    		}
    	}
    	return dp[dp.size()-1][n-1];
    }
};