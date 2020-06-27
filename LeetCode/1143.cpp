class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
    	s1 = ' ' + s1;
    	s2 = ' ' + s2;
    	int n1 = s1.length(), n2=s2.length();
    	vector<vector<int>> dp(n1, vector<int>(n2,0));
    	for(int i=1; i<n1; i++){
    		for(int j=1; j<n2; j++){
    			if(s1[i] == s2[j]){
    				dp[i][j] = 1 + dp[i-1][j-1];
    			}
    			else{
    				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    			}
    		}
    	}
    	return dp[n1-1][n2-1];
    }
};