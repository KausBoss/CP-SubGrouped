class Solution {
public:
    int minDistance(string s1, string s2) {
    	s1 = ' ' + s1;
    	s2 = ' ' + s2;
    	int n1 = s1.length(), n2 = s2.length();
    	vector<vector<int>> dp(n1, vector<int>(n2, 0));
    	for(int i=1; i<n1; i++){dp[i][0] = i;}
    	for(int i=1; i<n2; i++){dp[0][i] = i;}

    	for(int i=1; i<n1; i++){
    		for(int j=1; j<n2; j++){
    			if(s1[i] == s2[j]){
    				dp[i][j] = dp[i-1][j-1];
    			}
    			else{
    				dp[i][j] = 1 + min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]));
    			}
    		}
    	}

    	return dp[n1-1][n2-1];
    }
};