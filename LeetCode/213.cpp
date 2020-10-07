class Solution {
public:
    int rob(vector<int> a) {
        int n = a.size();
        if(n == 0){return 0;}
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][1] = a[0];
        int ans = dp[0][1];
        for(int i=1; i<n-1; i++){
        	
        }
    }
};